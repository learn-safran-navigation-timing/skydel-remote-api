#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use SetPseudorangeNoiseSineWaveForEachSV.
    /// 
    /// Set the satellite pseudorange noise sine wave attributes for all satellites.
    ///
    /// Name      Type         Description
    /// --------- ------------ ----------------------------------------------------------------
    /// System    string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SineWave  int          Sine wave number (0 or 1)
    /// Enabled   array bool   If true, sine wave is enabled
    /// Amplitude array double Sine wave amplitude in meters
    /// Period    array int    sine wave period in seconds
    /// Offset    array double Phase offset in radians
    ///

    class SetAllSatellitesPseudorangeNoiseSineWave;
    typedef std::shared_ptr<SetAllSatellitesPseudorangeNoiseSineWave> SetAllSatellitesPseudorangeNoiseSineWavePtr;
    
    
    class SetAllSatellitesPseudorangeNoiseSineWave : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetAllSatellitesPseudorangeNoiseSineWave();

      SetAllSatellitesPseudorangeNoiseSineWave(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset);

      static SetAllSatellitesPseudorangeNoiseSineWavePtr create(const std::string& system, int sineWave, const std::vector<bool>& enabled, const std::vector<double>& amplitude, const std::vector<int>& period, const std::vector<double>& offset);
      static SetAllSatellitesPseudorangeNoiseSineWavePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** sineWave ****
      int sineWave() const;
      void setSineWave(int sineWave);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);


      // **** amplitude ****
      std::vector<double> amplitude() const;
      void setAmplitude(const std::vector<double>& amplitude);


      // **** period ****
      std::vector<int> period() const;
      void setPeriod(const std::vector<int>& period);


      // **** offset ****
      std::vector<double> offset() const;
      void setOffset(const std::vector<double>& offset);
    };
    
  }
}

