#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use GetPseudorangeNoiseGaussMarkovForEachSV.
    /// 
    /// Get the satellite pseudorange noise Gauss-Markov process attributes for all satellites.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Process int    Gauss-Markov Process number (0 or 1)
    ///

    class GetAllSatellitesPseudorangeNoiseGaussMarkov;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseGaussMarkov> GetAllSatellitesPseudorangeNoiseGaussMarkovPtr;
    
    
    class GetAllSatellitesPseudorangeNoiseGaussMarkov : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllSatellitesPseudorangeNoiseGaussMarkov();

      GetAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system, int process);

      static GetAllSatellitesPseudorangeNoiseGaussMarkovPtr create(const std::string& system, int process);
      static GetAllSatellitesPseudorangeNoiseGaussMarkovPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

