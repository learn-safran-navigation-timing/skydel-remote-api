#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle circular trajectory
    ///
    /// 
    ///

    class GetVehicleTrajectoryCircular;
    typedef std::shared_ptr<GetVehicleTrajectoryCircular> GetVehicleTrajectoryCircularPtr;
    
    
    class GetVehicleTrajectoryCircular : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryCircular();

      static GetVehicleTrajectoryCircularPtr create();
      static GetVehicleTrajectoryCircularPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

