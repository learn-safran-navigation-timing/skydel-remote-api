#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise Gauss-Markov process attributes for all satellites.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Process int    Gauss-Markov Process number (0 or 1)
    ///

    class GetPseudorangeNoiseGaussMarkovForEachSV;
    typedef std::shared_ptr<GetPseudorangeNoiseGaussMarkovForEachSV> GetPseudorangeNoiseGaussMarkovForEachSVPtr;
    
    
    class GetPseudorangeNoiseGaussMarkovForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseGaussMarkovForEachSV();

      GetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system, int process);

      static GetPseudorangeNoiseGaussMarkovForEachSVPtr create(const std::string& system, int process);
      static GetPseudorangeNoiseGaussMarkovForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** process ****
      int process() const;
      void setProcess(int process);
    };
    
  }
}

