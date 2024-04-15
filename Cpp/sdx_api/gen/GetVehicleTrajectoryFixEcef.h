#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle static position and orientation
    ///
    /// 
    ///

    class GetVehicleTrajectoryFixEcef;
    typedef std::shared_ptr<GetVehicleTrajectoryFixEcef> GetVehicleTrajectoryFixEcefPtr;
    
    
    class GetVehicleTrajectoryFixEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleTrajectoryFixEcef();

      static GetVehicleTrajectoryFixEcefPtr create();
      static GetVehicleTrajectoryFixEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

