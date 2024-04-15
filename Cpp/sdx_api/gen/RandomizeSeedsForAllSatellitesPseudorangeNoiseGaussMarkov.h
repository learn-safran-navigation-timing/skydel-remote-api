#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV.
    /// 
    /// Generate new seeds for pseudorange noise Gauss-Markov process error on all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov;
    typedef std::shared_ptr<RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov> RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr;
    
    
    class RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov();

      RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system);

      static RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr create(const std::string& system);
      static RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

