#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use GetPseudorangeNoiseSineWaveForEachSV.
    /// 
    /// Get the satellite pseudorange noise sine wave attributes for all satellites.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SineWave int    Sine wave number (0 or 1)
    ///

    class GetAllSatellitesPseudorangeNoiseSineWave;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseSineWave> GetAllSatellitesPseudorangeNoiseSineWavePtr;
    
    
    class GetAllSatellitesPseudorangeNoiseSineWave : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSatellitesPseudorangeNoiseSineWave();

      GetAllSatellitesPseudorangeNoiseSineWave(const std::string& system, int sineWave);

      static GetAllSatellitesPseudorangeNoiseSineWavePtr create(const std::string& system, int sineWave);
      static GetAllSatellitesPseudorangeNoiseSineWavePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** sineWave ****
      int sineWave() const;
      void setSineWave(int sineWave);
    };
    
  }
}

