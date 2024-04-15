#pragma once

#include <memory>
#include "command_base.h"

#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
    ///
    /// Name Type            Description
    /// ---- --------------- --------------------
    /// Band GNSSBand        Frequency band
    /// Name optional string Vehicle antenna name
    ///

    class GetVehicleAntennaPhaseOffset;
    typedef std::shared_ptr<GetVehicleAntennaPhaseOffset> GetVehicleAntennaPhaseOffsetPtr;
    
    
    class GetVehicleAntennaPhaseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaPhaseOffset();

      GetVehicleAntennaPhaseOffset(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static GetVehicleAntennaPhaseOffsetPtr create(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});
      static GetVehicleAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

