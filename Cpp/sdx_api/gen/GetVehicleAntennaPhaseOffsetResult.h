#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleAntennaPhaseOffset.
    ///
    /// Name        Type               Description
    /// ----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------
    /// PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type        AntennaPatternType Pattern type
    /// Band        GNSSBand           Frequency band
    /// Name        optional string    Vehicle antenna name
    ///

    class GetVehicleAntennaPhaseOffsetResult;
    typedef std::shared_ptr<GetVehicleAntennaPhaseOffsetResult> GetVehicleAntennaPhaseOffsetResultPtr;
    
    
    class GetVehicleAntennaPhaseOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaPhaseOffsetResult();

      GetVehicleAntennaPhaseOffsetResult(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});

      GetVehicleAntennaPhaseOffsetResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});

      static GetVehicleAntennaPhaseOffsetResultPtr create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});

      static GetVehicleAntennaPhaseOffsetResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});
      static GetVehicleAntennaPhaseOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** phaseOffset ****
      std::vector<std::vector<double>> phaseOffset() const;
      void setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      std::optional<std::string> name() const;
      void setName(const std::optional<std::string>& name);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaPhaseOffsetResult);
  }
}

