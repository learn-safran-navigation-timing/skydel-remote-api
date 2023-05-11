#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVAntennaPhaseOffset.
    ///
    /// Name        Type               Description
    /// ----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------
    /// PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type        AntennaPatternType Pattern type
    /// Band        GNSSBand           Frequency band
    /// System      string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Name        optional string    SV antenna name
    ///

    class GetSVAntennaPhaseOffsetResult;
    typedef std::shared_ptr<GetSVAntennaPhaseOffsetResult> GetSVAntennaPhaseOffsetResultPtr;
    
    
    class GetSVAntennaPhaseOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaPhaseOffsetResult();

      GetSVAntennaPhaseOffsetResult(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      GetSVAntennaPhaseOffsetResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static GetSVAntennaPhaseOffsetResultPtr create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static GetSVAntennaPhaseOffsetResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});
      static GetSVAntennaPhaseOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** phaseOffset ****
      std::vector<std::vector<double>> phaseOffset() const;
      void setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSVAntennaPhaseOffsetResult);
  }
}

