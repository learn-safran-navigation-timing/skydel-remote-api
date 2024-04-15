#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle type for Route Trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne")
    ///

    class SetVehicleType;
    typedef std::shared_ptr<SetVehicleType> SetVehicleTypePtr;
    
    
    class SetVehicleType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetVehicleType();

      SetVehicleType(const std::string& type);

      static SetVehicleTypePtr create(const std::string& type);
      static SetVehicleTypePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);
    };
    
  }
}

