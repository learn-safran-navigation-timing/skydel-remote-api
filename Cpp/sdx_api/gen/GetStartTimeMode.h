#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation start time mode.
    ///
    /// 
    ///

    class GetStartTimeMode;
    typedef std::shared_ptr<GetStartTimeMode> GetStartTimeModePtr;
    
    
    class GetStartTimeMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStartTimeMode();

      static GetStartTimeModePtr create();
      static GetStartTimeModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

