#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes
    ///
    /// 
    ///

    class IsSimulationStopAtTrajectoryEndEnabled;
    typedef std::shared_ptr<IsSimulationStopAtTrajectoryEndEnabled> IsSimulationStopAtTrajectoryEndEnabledPtr;
    
    
    class IsSimulationStopAtTrajectoryEndEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSimulationStopAtTrajectoryEndEnabled();

      static IsSimulationStopAtTrajectoryEndEnabledPtr create();
      static IsSimulationStopAtTrajectoryEndEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

