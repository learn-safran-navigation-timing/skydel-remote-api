#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSatellitePseudorangeNoiseSineWave is deprecated since 21.3. You may use GetPseudorangeNoiseSineWaveForSV.
    /// 
    /// Get the satellite pseudorange noise sine wave attributes.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------------------------------------------------
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn      int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// SineWave int    Sine wave number (0 or 1)
    ///

    class GetSatellitePseudorangeNoiseSineWave;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseSineWave> GetSatellitePseudorangeNoiseSineWavePtr;
    
    
    class GetSatellitePseudorangeNoiseSineWave : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseSineWave();

      GetSatellitePseudorangeNoiseSineWave(const std::string& system, int prn, int sineWave);
  
      static GetSatellitePseudorangeNoiseSineWavePtr create(const std::string& system, int prn, int sineWave);
      static GetSatellitePseudorangeNoiseSineWavePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** sineWave ****
      int sineWave() const;
      void setSineWave(int sineWave);
    };
  }
}

