#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
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
    /// Result of GetVehicleAntennaGain.
    ///
    /// Name Type               Description
    /// ---- ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type AntennaPatternType Pattern type
    /// Band GNSSBand           Frequency band
    /// Name optional string    Vehicle antenna name
    ///

    class GetVehicleAntennaGainResult;
    typedef std::shared_ptr<GetVehicleAntennaGainResult> GetVehicleAntennaGainResultPtr;
    
    
    class GetVehicleAntennaGainResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaGainResult();

      GetVehicleAntennaGainResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      GetVehicleAntennaGainResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static GetVehicleAntennaGainResultPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static GetVehicleAntennaGainResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});
      static GetVehicleAntennaGainResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** gain ****
      std::vector<std::vector<double>> gain() const;
      void setGain(const std::vector<std::vector<double>>& gain);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleAntennaGainResult);
  }
}

