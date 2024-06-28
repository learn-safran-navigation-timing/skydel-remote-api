#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) connections to an NTP server.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------
    /// Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.
    ///

    class EnableNtpClient;
    typedef std::shared_ptr<EnableNtpClient> EnableNtpClientPtr;
    
    
    class EnableNtpClient : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableNtpClient();

      EnableNtpClient(bool enabled);

      static EnableNtpClientPtr create(bool enabled);
      static EnableNtpClientPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

