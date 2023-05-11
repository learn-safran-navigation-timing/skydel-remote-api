#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Set interference vehicle type for Track Trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxVehicleType;
    typedef std::shared_ptr<GetIntTxVehicleType> GetIntTxVehicleTypePtr;
    
    
    class GetIntTxVehicleType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxVehicleType();

      GetIntTxVehicleType(const std::string& id);

      static GetIntTxVehicleTypePtr create(const std::string& id);
      static GetIntTxVehicleTypePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

