#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise Gauss-Markov process attributes.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    Satellite SV ID.
    /// Process int    Gauss-Markov Process number (0 or 1)
    ///

    class GetPseudorangeNoiseGaussMarkovForSV;
    typedef std::shared_ptr<GetPseudorangeNoiseGaussMarkovForSV> GetPseudorangeNoiseGaussMarkovForSVPtr;
    
    
    class GetPseudorangeNoiseGaussMarkovForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseGaussMarkovForSV();

      GetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process);

      static GetPseudorangeNoiseGaussMarkovForSVPtr create(const std::string& system, int svId, int process);
      static GetPseudorangeNoiseGaussMarkovForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** process ****
      int process() const;
      void setProcess(int process);
    };
    
  }
}

