#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Indicates if the NTP client is enabled.
    ///
    /// 
    ///

    class IsNtpClientEnabled;
    typedef std::shared_ptr<IsNtpClientEnabled> IsNtpClientEnabledPtr;
    
    
    class IsNtpClientEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsNtpClientEnabled();

      static IsNtpClientEnabledPtr create();
      static IsNtpClientEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

