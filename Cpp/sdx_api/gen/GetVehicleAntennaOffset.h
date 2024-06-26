#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the vehicle antenna offset infos. If no name is specified, the default vehicle antenna is get.
    ///
    /// Name Type            Description
    /// ---- --------------- ---------------------------
    /// Name optional string Unique vehicle antenna name
    ///

    class GetVehicleAntennaOffset;
    typedef std::shared_ptr<GetVehicleAntennaOffset> GetVehicleAntennaOffsetPtr;
    
    
    class GetVehicleAntennaOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaOffset(const std::optional<std::string>& name = {});

      static GetVehicleAntennaOffsetPtr create(const std::optional<std::string>& name = {});
      static GetVehicleAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::optional<std::string> name() const;
      void setName(const std::optional<std::string>& name);
    };
    
  }
}

