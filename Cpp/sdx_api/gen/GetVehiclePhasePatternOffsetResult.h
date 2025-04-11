#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehiclePhasePatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// Offset      double          Phase offset (in rad)
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetVehiclePhasePatternOffsetResult;
    typedef std::shared_ptr<GetVehiclePhasePatternOffsetResult> GetVehiclePhasePatternOffsetResultPtr;
    
    
    class GetVehiclePhasePatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehiclePhasePatternOffsetResult();

      GetVehiclePhasePatternOffsetResult(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});

      GetVehiclePhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});

      static GetVehiclePhasePatternOffsetResultPtr create(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});

      static GetVehiclePhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {});
      static GetVehiclePhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
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
      std::optional<std::string> antennaName() const;
      void setAntennaName(const std::optional<std::string>& antennaName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehiclePhasePatternOffsetResult);
  }
}

