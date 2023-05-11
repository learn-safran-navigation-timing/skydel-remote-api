#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// If enabled, simulation stops when a command result fail.
    ///
    /// 
    ///

    class IsSimStopWhenCommandFailEnabled;
    typedef std::shared_ptr<IsSimStopWhenCommandFailEnabled> IsSimStopWhenCommandFailEnabledPtr;
    
    
    class IsSimStopWhenCommandFailEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSimStopWhenCommandFailEnabled();

      static IsSimStopWhenCommandFailEnabledPtr create();
      static IsSimStopWhenCommandFailEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

