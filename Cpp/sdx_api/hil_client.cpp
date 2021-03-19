#include "hil_client.h"

#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#ifdef WINSOCK1
#include <winsock.h>
#else
#include <winsock2.h>
#endif
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <poll.h>
#include <endian.h>
#endif

#include "lla.h"
#include "ecef.h"
#include <cstring>
#include <iostream>
#include "vehicle_info.h"

#define HIL_BLOCK_SIZE 255

namespace Sdx
{

struct HilClient::Pimpl
{
  std::string errorMessage;

  int s;
  struct hostent* server;
  struct sockaddr_in servAddr;
  bool connected;
  char message[HIL_BLOCK_SIZE];
  bool stopRequest;
  bool exceptionOnError;
  bool verbose;
};

HilClient::HilClient(bool exceptionOnError) : m(new Pimpl)
{
  m->s = -1;
  m->server = 0;
  m->connected = false;
  m->exceptionOnError = exceptionOnError;
  m->verbose = false;
#if _WIN32
  WORD versionWanted = MAKEWORD(2, 0);
  WSADATA wsaData;
  WSAStartup(versionWanted, &wsaData);
#endif
}

HilClient::~HilClient(void)
{
  disconnect();
  delete m;
#if _WIN32
  WSACleanup();
#endif
}

bool HilClient::hasError() const
{
  return !m->errorMessage.empty();
}

void HilClient::clearError()
{
  m->errorMessage.clear();
}

void HilClient::setVerbose(bool verbose)
{
  m->verbose = verbose;
}

bool HilClient::isVerbose() const
{
  return m->verbose;
}

bool HilClient::connectToHost(const std::string& ip, int port)
{
  m->s = (int) socket(AF_INET, SOCK_DGRAM, 0);
  if (m->s < 0)
  {
    m->s = -1;
    errorMessage("Unable to create socket");
    return false;
  }
  m->server = gethostbyname(ip.c_str());
  if (!m->server)
  {
    disconnect();
    errorMessage("Unable to get host by name");
    return false;
  }
  memset(&m->servAddr, 0, sizeof(m->servAddr));
  m->servAddr.sin_family = AF_INET;
  memcpy(&m->servAddr.sin_addr.s_addr, m->server->h_addr, m->server->h_length);
  m->servAddr.sin_port = htons(port);
  if (connect(m->s, (struct sockaddr*)&m->servAddr, sizeof(m->servAddr)) < 0)
  {
    disconnect();
    errorMessage("Unable to connect to the Simulator HIL Server");
    return false;
  }
  m->connected = true;

  //Send Hello
  char message = HilMsgId_Hello;
  return sendMessage(&message, 1);
}

void HilClient::errorMessage(const std::string& msg)
{
  m->errorMessage = msg;
  if(m->exceptionOnError)
    throw std::runtime_error(msg);
  if (m->verbose)
    std::cout << msg << std::endl;
}

bool HilClient::isConnected() const
{
  return m->connected;
}

template<typename T>
void append(char*& ptr, const T& value)
{
	memcpy(ptr, &value, sizeof(T));
	ptr += sizeof(T);
}

bool HilClient::pushEcef(long long elapsedTime, const Ecef& ecef, const std::string& name)
{
  std::size_t size = 37 + name.size();
  char* message = new char[size];
  char* ptr = message;

  append(ptr, (char)HilMsgId_PushEcef);
  append(ptr, elapsedTime);
  append(ptr, ecef.x);
  append(ptr, ecef.y);
  append(ptr, ecef.z);
  append(ptr, (unsigned int)name.size());

  memcpy(ptr, name.c_str(), name.size());
  bool result = sendMessage(message, 37 + (int)name.size());
  delete[] message;
  return result;
}

bool HilClient::pushEcefNed(long long elapsedTime, const Ecef& ecef, const Attitude& attitude, const std::string& name)
{
  std::size_t size = 61 + name.size();
  char* message = new char[size];
  char* ptr = message;

  append(ptr, (char)HilMsgId_PushEcefNed);
  append(ptr, elapsedTime);
  append(ptr, ecef.x);
  append(ptr, ecef.y);
  append(ptr, ecef.z);
  append(ptr, attitude.yaw);
  append(ptr, attitude.pitch);
  append(ptr, attitude.roll);
  append(ptr, (unsigned int)name.size());

  memcpy(ptr, name.c_str(), name.size());
  bool result = sendMessage(message, 61 + (int)name.size());
  delete[] message;
  return result;
}

bool HilClient::hasRecvVehicleInfo(int timeout, bool errorAtTimeout)
{
  int ret;
#if _WIN32
  fd_set fds;
  struct timeval tv;

  // Set up the file descriptor set.
  FD_ZERO(&fds);
  FD_SET(m->s, &fds);

  // Set up the struct timeval for the timeout.
  tv.tv_sec = 0;
  tv.tv_usec = timeout*1000;

  // Wait until timeout or data received.
  ret = select(m->s, &fds, NULL, NULL, &tv);
#else
  struct pollfd fd;

  fd.fd = m->s;
  fd.events = POLLIN;
  ret = poll(&fd, 1, timeout);
#endif

  switch (ret)
  {
  case -1:
    errorMessage("Error while receiving vehicle info");
    disconnect();
    return false;
  case 0:
    if(errorAtTimeout)
      errorMessage("Failed to receive vehicle info. Is simulation running and beginVehicleInfo() called before start?");
    return false;
  default:
    return true;
  }
}

void HilClient::clearVehicleInfo()
{
  while(hasRecvVehicleInfo(0, false))
  {
    if(!receiveMessage())
      return;
  }
}

bool HilClient::recvLastVehicleInfo(VehicleInfo& simStats)
{
  // Client expects LastVehicleInfo to be blocking. We block for 10s max.
  if(hasRecvVehicleInfo(10000))
  {
    do
    {
      if(!receiveMessage())
        return false;
    }
    while(hasRecvVehicleInfo(0, false));

    return recvVehicleInfo(simStats);
  }
  return false;
}

bool HilClient::recvNextVehicleInfo(VehicleInfo& simStats)
{
  if(hasRecvVehicleInfo(200))
  {
    if(receiveMessage())
      return recvVehicleInfo(simStats);
  }
  return false;
}


bool HilClient::recvVehicleInfo(VehicleInfo& simStats)
{
  if(m->message[0] == HilMsgId_VehicleInfo)
  {
    memcpy(&simStats.elapsedTime, &m->message[1], 8);
    memcpy(&simStats.ecef, &m->message[9], 24);
    memcpy(&simStats.attitude, &m->message[33], 24);
    memcpy(&simStats.speed, &m->message[57], 8);
    memcpy(&simStats.heading, &m->message[65], 8);
    memcpy(&simStats.odometer, &m->message[73], 8);

    return true;
  }

  return false;
}

void HilClient::disconnect()
{
  if (m->s < 0)
    return;

  //Send Bye
  char message = HilMsgId_Bye;
  sendMessage(&message, 1);

#ifdef _WIN32
  closesocket(m->s);
#else
  close(m->s);
#endif
  m->s = -1;
  m->connected = false;
}

bool HilClient::sendMessage(const char* message, int length)
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

bool HilClient::receiveMessage()
{
  int rx = recv(m->s, m->message, HIL_BLOCK_SIZE, 0);
  if (rx <= 0)
  {
    errorMessage("Error while receiving udp message");
    disconnect();
    return false;
  }

  return true;
}

} // namespace Sdx
