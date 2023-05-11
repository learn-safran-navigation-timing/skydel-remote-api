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
    /// Result of GetSVAntennaGain.
    ///
    /// Name   Type               Description
    /// ------ ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain   array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type   AntennaPatternType Pattern type
    /// Band   GNSSBand           Frequency band
    /// System string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Name   optional string    SV antenna name
    ///

    class GetSVAntennaGainResult;
    typedef std::shared_ptr<GetSVAntennaGainResult> GetSVAntennaGainResultPtr;
    
    
    class GetSVAntennaGainResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaGainResult();

      GetSVAntennaGainResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      GetSVAntennaGainResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static GetSVAntennaGainResultPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static GetSVAntennaGainResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});
      static GetSVAntennaGainResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** gain ****
      std::vector<std::vector<double>> gain() const;
      void setGain(const std::vector<std::vector<double>>& gain);


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSVAntennaGainResult);
  }
}

