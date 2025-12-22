#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Gets the vehicle's current ECEF position, or its initial position if the simulation is not running.
    /// 
    /// Note: This command does not work with HIL trajectories in IDLE mode.
    ///
    /// 
    ///

    class GetVehiclePositionEcef;
    typedef std::shared_ptr<GetVehiclePositionEcef> GetVehiclePositionEcefPtr;
    
    
    class GetVehiclePositionEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehiclePositionEcef();

      static GetVehiclePositionEcefPtr create();
      static GetVehiclePositionEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

