#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle trajectory type
    ///
    /// 
    ///

    class GetVehicleTrajectory;
    typedef std::shared_ptr<GetVehicleTrajectory> GetVehicleTrajectoryPtr;
    
    
    class GetVehicleTrajectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectory();

      static GetVehicleTrajectoryPtr create();
      static GetVehicleTrajectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

