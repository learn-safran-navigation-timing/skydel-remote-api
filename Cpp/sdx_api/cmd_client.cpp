#include "cmd_client.h"

#if _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#ifdef WINSOCK1
#include <winsock.h>
#define MSG_WAITALL 0
#else
#include <winsock2.h>
#endif
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include <chrono>
#include <iostream>

#include "all_commands.h"
#include "command_base.h"
#include "command_result.h"
#include "command_result_factory.h"

#define CMD_BLOCK_SIZE 65535

namespace Sdx
{

struct CmdClient::Pimpl
{
  std::string error_message;

  int s;
  struct hostent* server;
  struct sockaddr_in serv_addr;
  bool connected;
  char message2Send[CMD_BLOCK_SIZE];
  char message[CMD_BLOCK_SIZE];
  std::string address;
  bool stop_request;
  bool exceptionOnError;
  bool verbose;
};

CmdClient::CmdClient(bool exceptionOnError) : m(new Pimpl)
{
  m->s = -1;
  m->server = 0;
  m->connected = false;
  m->exceptionOnError = exceptionOnError;
  m->verbose = false;
  m->stop_request = false;
#if _WIN32
  WORD versionWanted = MAKEWORD(2, 0);
  WSADATA wsaData;
  WSAStartup(versionWanted, &wsaData);
#endif
}

CmdClient::~CmdClient(void)
{
  m->stop_request = true;
  closeSocket();

  delete m;
#if _WIN32
  WSACleanup();
#endif
}

int CmdClient::port() const
{
  return (int)m->serv_addr.sin_port;
}

const std::string& CmdClient::address() const
{
  return m->address;
}

bool CmdClient::hasError() const
{
  return !m->error_message.empty();
}

void CmdClient::clearError()
{
  m->error_message.clear();
}

bool CmdClient::connectToHost(const std::string& ip, int port)
{
  m->s = socket(AF_INET, SOCK_STREAM, 0);
  if (m->s < 0)
  {
    m->s = -1;
    errorMessage("Unable to create socket");
    return false;
  }

  m->address = ip;
  m->server = gethostbyname(ip.c_str());
  if (!m->server)
  {
    closeSocket();
    errorMessage("Unable to get host by name");
    return false;
  }
  memset(&m->serv_addr, 0, sizeof(m->serv_addr));
  m->serv_addr.sin_family = AF_INET;
  memcpy(&m->serv_addr.sin_addr.s_addr, m->server->h_addr, m->server->h_length);
  m->serv_addr.sin_port = htons(static_cast<u_short>(port));

#ifndef _WIN32
  // Add a 10 second timeout to the socket SEND calls
  timeval timeout {10, 0};
  setsockopt(m->s, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
#endif

  if (connect(m->s, (struct sockaddr*)&m->serv_addr, sizeof(m->serv_addr)) < 0)
  {
    closeSocket();
    errorMessage("Unable to connect to the Simulator. Please, make sure that the simulator process is running");
    return false;
  }
  m->connected = true;
  return true;
}

void CmdClient::setVerbose(bool verbose)
{
  m->verbose = verbose;
}

bool CmdClient::isVerbose() const
{
  return m->verbose;
}

void CmdClient::errorMessage(const std::string& msg)
{
  m->error_message = msg;
  if (m->exceptionOnError)
    throw std::runtime_error(msg);
  if (m->verbose)
    std::cout << msg << std::endl;
}

bool CmdClient::isConnected() const
{
  return m->connected;
}

int CmdClient::getServerApiVersion()
{
  int msgSize = 7;
  ((uint16_t*)&m->message2Send)[0] = msgSize - 2;
  m->message2Send[2] = (char)CmdMsgId_ApiVersion;
  ((uint32_t*)&m->message2Send[3])[0] = COMMANDS_API_VERSION;

  if (sendMessage(m->message2Send, msgSize))
  {
    while (true)
    {
      if (!receiveMessage())
        return 0;

      int msgId = (int)m->message[2];
      switch (msgId)
      {
        case CmdMsgId_ApiVersion:
          return ((uint32_t*)&m->message[3])[0];
        default:
          break;
      }
    }
  }

  return 0;
}

bool CmdClient::sendCommand(CommandBasePtr cmd)
{
  std::string jsonStr = cmd->toString();
  m->message2Send[2] = (char)CmdMsgId_Command;
  memcpy(&m->message2Send[3], jsonStr.c_str(), jsonStr.size() + 1);

  int msgSize = (int)jsonStr.size() + 4;
  ((uint16_t*)&m->message2Send)[0] = msgSize - 2;

  return sendMessage(m->message2Send, msgSize);
}

CommandResultPtr CmdClient::waitCommand(CommandBasePtr cmd)
{
  while (true)
  {
    if (!receiveMessage())
    {
      std::cout << "Failed to receive command result. Is server still running?" << std::endl;
      throw std::runtime_error("Failed to receive command result. Is server still running?");
    }

    int msgId = (int)m->message[2];
    switch (msgId)
    {
      case CmdMsgId_Result:
      {
        char* msgJson = &m->message[7];
        std::string errorMsg;
        CommandResultPtr result = CommandResultFactory::instance()->createCommandResult(msgJson, &errorMsg);
        if (!result)
        {
          std::cout << "Failed to parse " << msgJson << std::endl;
          std::cout << errorMsg << std::endl;
          throw std::runtime_error(errorMsg.c_str());
        }
        if (cmd->uuid() == result->relatedCommand()->uuid())
          return result;
        break;
      }
      default:
        break;
    }
  }
}

bool CmdClient::receiveMessage()
{
  int rx(0);

  do
  {
    rx = recv(m->s, m->message, 2, MSG_PEEK);

    if (rx <= 0)
    {
      checkStopRequest();
      return false;
    }
  } while (rx < 2);

  int bytesToRead = (int)((uint16_t*)&m->message[0])[0] + 2;
  char* messagePtr = m->message;

  do
  {
    rx = recv(m->s, messagePtr, bytesToRead, MSG_WAITALL);

    if (rx <= 0)
    {
      checkStopRequest();
      return false;
    }

    bytesToRead -= rx;
    messagePtr += rx;
  } while (bytesToRead > 0);

  return true;
}

#ifndef _WIN32
bool haveInput(int fd, double timeout)
{
  int status;
  fd_set fds;
  struct timeval tv;
  FD_ZERO(&fds);
  FD_SET(fd, &fds);
  tv.tv_sec = (long)timeout;                            // cast needed for C++
  tv.tv_usec = (long)((timeout - tv.tv_sec) * 1000000); // 'suseconds_t'

  while (1)
  {
    if (!(status = select(fd + 1, &fds, 0, 0, &tv)))
      return false;
    else if (status > 0 && FD_ISSET(fd, &fds))
      return true;
    else if (status > 0 || errno != EINTR)
      return false;
  }
}

double getWallTimeEpoch()
{
  using namespace std::chrono;
  return duration_cast<seconds>(high_resolution_clock::now().time_since_epoch()).count();
}

bool flushSocketBeforeClose(int fd, double timeout)
{
  const double start = getWallTimeEpoch();
  char discard[99];
  if (shutdown(fd, 1) != -1)
    while (getWallTimeEpoch() < start + timeout)
      while (haveInput(fd, 0.01)) // can block for 0.01 secs
        return !read(fd, discard, sizeof discard);
  return false;
}
#endif

void CmdClient::closeSocket()
{
  if (m->s < 0)
    return;
#ifdef _WIN32
  closesocket(m->s);
#else
  flushSocketBeforeClose(m->s, 1.0);
  close(m->s);
#endif

  m->s = -1;
  m->connected = false;
}

void CmdClient::checkStopRequest()
{
  m->connected = false;
  if (!m->stop_request)
  {
    errorMessage("Connection lost with host");
  }
}

bool CmdClient::sendMessage(const char* message, int length)
{
  if (!m->connected)
  {
    return false;
  }
  if (length != send(m->s, message, length, 0))
  {
    errorMessage("Error sending message.");
    return false;
  }
  return true;
}

} // namespace Sdx
