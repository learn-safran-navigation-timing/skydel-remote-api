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
    /// Name    Type Description
    /// ------- ---- ----------------------------------
    /// Enabled bool Enable stop when command fail flag
    ///

    class StopWhenCommandFail;
    typedef std::shared_ptr<StopWhenCommandFail> StopWhenCommandFailPtr;
    
    
    class StopWhenCommandFail : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      StopWhenCommandFail();

      StopWhenCommandFail(bool enabled);

      static StopWhenCommandFailPtr create(bool enabled);
      static StopWhenCommandFailPtr dynamicCast(CommandBasePtr ptr);
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

