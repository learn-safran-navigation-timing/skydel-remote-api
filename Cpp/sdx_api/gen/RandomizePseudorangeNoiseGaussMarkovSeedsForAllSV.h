#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Generate new seeds for pseudorange noise Gauss-Markov process error on all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV;
    typedef std::shared_ptr<RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV> RandomizePseudorangeNoiseGaussMarkovSeedsForAllSVPtr;
    
    
    class RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV();

      RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV(const std::string& system);

      static RandomizePseudorangeNoiseGaussMarkovSeedsForAllSVPtr create(const std::string& system);
      static RandomizePseudorangeNoiseGaussMarkovSeedsForAllSVPtr dynamicCast(CommandBasePtr ptr);
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

