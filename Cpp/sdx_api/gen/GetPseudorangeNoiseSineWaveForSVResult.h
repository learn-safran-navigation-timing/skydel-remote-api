#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeNoiseSineWaveForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------------
    /// System    string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId      int    The satellite's SV ID
    /// SineWave  int    Sine wave number (0 or 1)
    /// Enabled   bool   If true, sine wave is enabled
    /// Amplitude double Sine wave amplitude in meters
    /// Period    int    Sine wave period in seconds (minimum 3 seconds)
    /// Offset    double Phase offset in radians
    ///

    class GetPseudorangeNoiseSineWaveForSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForSVResult> GetPseudorangeNoiseSineWaveForSVResultPtr;
    
    
    class GetPseudorangeNoiseSineWaveForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeNoiseSineWaveForSVResult();

      GetPseudorangeNoiseSineWaveForSVResult(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);

      GetPseudorangeNoiseSineWaveForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);

      static GetPseudorangeNoiseSineWaveForSVResultPtr create(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);

      static GetPseudorangeNoiseSineWaveForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);
      static GetPseudorangeNoiseSineWaveForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** sineWave ****
      int sineWave() const;
      void setSineWave(int sineWave);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** amplitude ****
      double amplitude() const;
      void setAmplitude(double amplitude);


      // **** period ****
      int period() const;
      void setPeriod(int period);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseSineWaveForSVResult);
  }
}

