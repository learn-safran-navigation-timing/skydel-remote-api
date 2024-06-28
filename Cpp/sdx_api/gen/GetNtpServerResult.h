#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNtpServer.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------------------
    /// Address string       IP Address of the NTP server.
    /// Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.
    ///

    class GetNtpServerResult;
    typedef std::shared_ptr<GetNtpServerResult> GetNtpServerResultPtr;
    
    
    class GetNtpServerResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNtpServerResult();

      GetNtpServerResult(const std::string& address, const std::optional<int>& port = {});

      GetNtpServerResult(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port = {});

      static GetNtpServerResultPtr create(const std::string& address, const std::optional<int>& port = {});

      static GetNtpServerResultPtr create(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port = {});
      static GetNtpServerResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);


      // **** port ****
      std::optional<int> port() const;
      void setPort(const std::optional<int>& port);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNtpServerResult);
  }
}

