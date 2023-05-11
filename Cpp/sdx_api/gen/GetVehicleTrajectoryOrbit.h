#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get earth-orbiting spacecraft trajectory.
    ///
    /// 
    ///

    class GetVehicleTrajectoryOrbit;
    typedef std::shared_ptr<GetVehicleTrajectoryOrbit> GetVehicleTrajectoryOrbitPtr;
    
    
    class GetVehicleTrajectoryOrbit : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryOrbit();

      static GetVehicleTrajectoryOrbitPtr create();
      static GetVehicleTrajectoryOrbitPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

