#pragma once

#include <memory>
#include "command_base.h"

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
    /// Set space vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
    ///
    /// Name        Type               Description
    /// ----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------
    /// PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type        AntennaPatternType Pattern type
    /// Band        GNSSBand           Frequency band
    /// System      string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Name        optional string    SV antenna name
    ///

    class SetSVAntennaPhaseOffset;
    typedef std::shared_ptr<SetSVAntennaPhaseOffset> SetSVAntennaPhaseOffsetPtr;
    
    
    class SetSVAntennaPhaseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSVAntennaPhaseOffset();

      SetSVAntennaPhaseOffset(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static SetSVAntennaPhaseOffsetPtr create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});
      static SetSVAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

