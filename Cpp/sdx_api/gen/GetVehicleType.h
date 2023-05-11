#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle type for Route Trajectory
    ///
    /// 
    ///

    class GetVehicleType;
    typedef std::shared_ptr<GetVehicleType> GetVehicleTypePtr;
    
    
    class GetVehicleType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleType();

      static GetVehicleTypePtr create();
      static GetVehicleTypePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

