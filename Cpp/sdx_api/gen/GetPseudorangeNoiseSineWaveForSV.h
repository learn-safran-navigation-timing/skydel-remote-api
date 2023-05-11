#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise sine wave attributes.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId     int    The satellite's SV ID
    /// SineWave int    Sine wave number (0 or 1)
    ///

    class GetPseudorangeNoiseSineWaveForSV;
    typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForSV> GetPseudorangeNoiseSineWaveForSVPtr;
    
    
    class GetPseudorangeNoiseSineWaveForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseSineWaveForSV();

      GetPseudorangeNoiseSineWaveForSV(const std::string& system, int svId, int sineWave);

      static GetPseudorangeNoiseSineWaveForSVPtr create(const std::string& system, int svId, int sineWave);
      static GetPseudorangeNoiseSineWaveForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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
    };
    
  }
}

