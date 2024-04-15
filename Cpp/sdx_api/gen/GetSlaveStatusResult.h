#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSlaveStatus.
    ///
    /// Name        Type   Description
    /// ----------- ------ ---------------------------------------
    /// IsSlave     bool   True if Skydel is in slave mode
    /// IsConnected bool   True if Skydel is connected to a master
    /// HostName    string The host name, empty if not a slave
    /// HostPort    int    The host port, 0 if not a slave
    ///

    class GetSlaveStatusResult;
    typedef std::shared_ptr<GetSlaveStatusResult> GetSlaveStatusResultPtr;
    
    
    class GetSlaveStatusResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSlaveStatusResult();

      GetSlaveStatusResult(bool isSlave, bool isConnected, const std::string& hostName, int hostPort);

      GetSlaveStatusResult(CommandBasePtr relatedCommand, bool isSlave, bool isConnected, const std::string& hostName, int hostPort);

      static GetSlaveStatusResultPtr create(bool isSlave, bool isConnected, const std::string& hostName, int hostPort);

      static GetSlaveStatusResultPtr create(CommandBasePtr relatedCommand, bool isSlave, bool isConnected, const std::string& hostName, int hostPort);
      static GetSlaveStatusResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** isSlave ****
      bool isSlave() const;
      void setIsSlave(bool isSlave);


      // **** isConnected ****
      bool isConnected() const;
      void setIsConnected(bool isConnected);


      // **** hostName ****
      std::string hostName() const;
      void setHostName(const std::string& hostName);


      // **** hostPort ****
      int hostPort() const;
      void setHostPort(int hostPort);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSlaveStatusResult);
  }
}

