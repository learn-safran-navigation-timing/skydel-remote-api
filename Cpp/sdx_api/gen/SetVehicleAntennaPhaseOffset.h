#pragma once

#include <memory>
#include "command_base.h"

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
    /// Set Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
    ///
    /// Name        Type               Description
    /// ----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------
    /// PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type        AntennaPatternType Pattern type
    /// Band        GNSSBand           Frequency band
    /// Name        optional string    Vehicle antenna name
    ///

    class SetVehicleAntennaPhaseOffset;
    typedef std::shared_ptr<SetVehicleAntennaPhaseOffset> SetVehicleAntennaPhaseOffsetPtr;
    
    
    class SetVehicleAntennaPhaseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetVehicleAntennaPhaseOffset();

      SetVehicleAntennaPhaseOffset(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});

      static SetVehicleAntennaPhaseOffsetPtr create(const std::vector<std::vector<double>>& phaseOffset, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});
      static SetVehicleAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr);
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


      // **** name ****
      std::optional<std::string> name() const;
      void setName(const std::optional<std::string>& name);
    };
    
  }
}

