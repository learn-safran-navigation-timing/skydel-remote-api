#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
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


      GetVehicleAntennaOffset(const Sdx::optional<std::string>& name = {});

      static GetVehicleAntennaOffsetPtr create(const Sdx::optional<std::string>& name = {});
      static GetVehicleAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

