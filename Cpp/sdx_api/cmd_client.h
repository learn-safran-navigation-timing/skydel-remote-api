#ifndef CMD_CLIENT_H
#define CMD_CLIENT_H

#include <memory>
#include <string>
#include "command_base.h"

namespace Sdx
{

enum CmdMessageId
{
  CmdMsgId_Command = 0,
  CmdMsgId_Result = 1,
  CmdMsgId_ApiVersion = 2
};

class CmdClient
{
public:
  CmdClient(bool exceptionOnError);
  virtual ~CmdClient(void);

  bool hasError() const; // returns 0 if there are no errors
  void clearError();

  bool connectToHost(const std::string& ip, int port);
  bool isConnected() const;

  int getServerApiVersion();
  bool sendCommand(CommandBasePtr cmd);
  CommandResultPtr waitCommand(CommandBasePtr cmd);

  int port() const;
  const std::string& address() const;

  void setVerbose(bool verbose);
  bool isVerbose() const;

private:
  struct Pimpl;
  Pimpl* m;

  void checkStopRequest();
  void errorMessage(const std::string& msg);
  void closeSocket();
  bool receiveMessage();
  bool sendMessage(const char* message, int length);
};

} // namespace Sdx

#endif // CMD_CLIENT_H
