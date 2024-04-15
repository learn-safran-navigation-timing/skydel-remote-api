#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set interference vehicle type for Track Trajectory.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne").
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxVehicleType;
    typedef std::shared_ptr<SetIntTxVehicleType> SetIntTxVehicleTypePtr;
    
    
    class SetIntTxVehicleType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxVehicleType();

      SetIntTxVehicleType(const std::string& type, const std::string& id);

      static SetIntTxVehicleTypePtr create(const std::string& type, const std::string& id);
      static SetIntTxVehicleTypePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

