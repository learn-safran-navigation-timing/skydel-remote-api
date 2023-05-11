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

    class GetVehicleTrajectoryFix;
    typedef std::shared_ptr<GetVehicleTrajectoryFix> GetVehicleTrajectoryFixPtr;
    
    
    class GetVehicleTrajectoryFix : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryFix();

      static GetVehicleTrajectoryFixPtr create();
      static GetVehicleTrajectoryFixPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

