#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite pseudorange noise sine wave attributes.
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

    class SetPseudorangeNoiseSineWaveForSV;
    typedef std::shared_ptr<SetPseudorangeNoiseSineWaveForSV> SetPseudorangeNoiseSineWaveForSVPtr;
    
    
    class SetPseudorangeNoiseSineWaveForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPseudorangeNoiseSineWaveForSV();

      SetPseudorangeNoiseSineWaveForSV(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);

      static SetPseudorangeNoiseSineWaveForSVPtr create(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset);
      static SetPseudorangeNoiseSineWaveForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

