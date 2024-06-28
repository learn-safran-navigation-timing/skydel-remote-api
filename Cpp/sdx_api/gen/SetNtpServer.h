#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the connection parameters for the NTP Server from which the simulator will get the simulation start time.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------------------
    /// Address string       IP Address of the NTP server.
    /// Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.
    ///

    class SetNtpServer;
    typedef std::shared_ptr<SetNtpServer> SetNtpServerPtr;
    
    
    class SetNtpServer : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetNtpServer();

      SetNtpServer(const std::string& address, const std::optional<int>& port = {});

      static SetNtpServerPtr create(const std::string& address, const std::optional<int>& port = {});
      static SetNtpServerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);


      // **** port ****
      std::optional<int> port() const;
      void setPort(const std::optional<int>& port);
    };
    
  }
}

