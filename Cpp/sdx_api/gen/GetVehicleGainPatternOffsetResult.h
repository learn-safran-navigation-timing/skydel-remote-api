#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleGainPatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// Offset      double          Power offset
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetVehicleGainPatternOffsetResult;
    typedef std::shared_ptr<GetVehicleGainPatternOffsetResult> GetVehicleGainPatternOffsetResultPtr;
    
    
    class GetVehicleGainPatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleGainPatternOffsetResult();

      GetVehicleGainPatternOffsetResult(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});

      GetVehicleGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});

      static GetVehicleGainPatternOffsetResultPtr create(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});

      static GetVehicleGainPatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});
      static GetVehicleGainPatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** antennaName ****
      Sdx::optional<std::string> antennaName() const;
      void setAntennaName(const Sdx::optional<std::string>& antennaName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleGainPatternOffsetResult);
  }
}

