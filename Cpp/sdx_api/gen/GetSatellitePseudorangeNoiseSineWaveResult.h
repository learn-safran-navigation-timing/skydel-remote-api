#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSatellitePseudorangeNoiseSineWave.
    ///
    /// Name      Type   Description
    /// --------- ------ ----------------------------------------------------------------------------------------------------------
    /// System    string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn       int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// SineWave  int    Sine wave number (0 or 1)
    /// Enabled   bool   If true, sine wave is enabled
    /// Amplitude double Sine wave amplitude in meters
    /// Period    int    Sine wave period in seconds (minimum 3 seconds)
    /// Offset    double Phase offset in radians
    ///

    class GetSatellitePseudorangeNoiseSineWaveResult;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseSineWaveResult> GetSatellitePseudorangeNoiseSineWaveResultPtr;
    
    
    class GetSatellitePseudorangeNoiseSineWaveResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseSineWaveResult();

      GetSatellitePseudorangeNoiseSineWaveResult(CommandBasePtr relatedCommand, const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset);
  
      static GetSatellitePseudorangeNoiseSineWaveResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, int sineWave, bool enabled, double amplitude, int period, double offset);
      static GetSatellitePseudorangeNoiseSineWaveResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


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
  }
}

