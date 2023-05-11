#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the simulation start time mode.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------------
    /// Mode string Accepted Modes ("Custom", "Computer", "GPS")
    ///

    class SetStartTimeMode;
    typedef std::shared_ptr<SetStartTimeMode> SetStartTimeModePtr;
    
    
    class SetStartTimeMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetStartTimeMode();

      SetStartTimeMode(const std::string& mode);

      static SetStartTimeModePtr create(const std::string& mode);
      static SetStartTimeModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** mode ****
      std::string mode() const;
      void setMode(const std::string& mode);
    };
    
  }
}

