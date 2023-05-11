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
    /// Set space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.
    ///
    /// Name   Type               Description
    /// ------ ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain   array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type   AntennaPatternType Pattern type
    /// Band   GNSSBand           Frequency band
    /// System string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Name   optional string    SV antenna name
    ///

    class SetSVAntennaGain;
    typedef std::shared_ptr<SetSVAntennaGain> SetSVAntennaGainPtr;
    
    
    class SetSVAntennaGain : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSVAntennaGain();

      SetSVAntennaGain(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static SetSVAntennaGainPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});
      static SetSVAntennaGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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
    
  }
}

