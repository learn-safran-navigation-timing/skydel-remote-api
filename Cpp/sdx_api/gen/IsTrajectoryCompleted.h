#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns whether the vehicle trajectory was completed.
    /// For fixed, circular and earth-orbiting spacecraft, this will always return false.
    /// For track playback and vehicle simulation, this will return true once the vehicle will reach the last position in the track/route.
    /// The value is unreliable for HIL trajectories.
    ///
    /// 
    ///

    class IsTrajectoryCompleted;
    typedef std::shared_ptr<IsTrajectoryCompleted> IsTrajectoryCompletedPtr;
    
    
    class IsTrajectoryCompleted : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTrajectoryCompleted();

      static IsTrajectoryCompletedPtr create();
      static IsTrajectoryCompletedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

