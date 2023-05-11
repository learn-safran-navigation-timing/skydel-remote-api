#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle trajectory type
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------------------
    /// Type string Trajectory type ("Fix", "Circular", "HIL", "Track", "Route" or "Orbit")
    ///

    class SetVehicleTrajectory;
    typedef std::shared_ptr<SetVehicleTrajectory> SetVehicleTrajectoryPtr;
    
    
    class SetVehicleTrajectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetVehicleTrajectory();

      SetVehicleTrajectory(const std::string& type);

      static SetVehicleTrajectoryPtr create(const std::string& type);
      static SetVehicleTrajectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);
    };
    
  }
}

