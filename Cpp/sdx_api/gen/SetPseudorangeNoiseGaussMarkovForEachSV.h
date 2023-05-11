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
    /// Set the satellite pseudorange noise Gauss-Markov process attributes for all satellites.
    ///
    /// Name    Type         Description
    /// ------- ------------ ----------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Process int          Gauss-Markov Process number (0 or 1)
    /// Enabled array bool   If true, Gauss-Markov process is enabled
    /// Sigma   array double Standard devition
    /// Time    array double Time constant
    /// Seed    array int    Random seed
    ///

    class SetPseudorangeNoiseGaussMarkovForEachSV;
    typedef std::shared_ptr<SetPseudorangeNoiseGaussMarkovForEachSV> SetPseudorangeNoiseGaussMarkovForEachSVPtr;
    
    
    class SetPseudorangeNoiseGaussMarkovForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPseudorangeNoiseGaussMarkovForEachSV();

      SetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);

      static SetPseudorangeNoiseGaussMarkovForEachSVPtr create(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);
      static SetPseudorangeNoiseGaussMarkovForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** process ****
      int process() const;
      void setProcess(int process);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);


      // **** sigma ****
      std::vector<double> sigma() const;
      void setSigma(const std::vector<double>& sigma);


      // **** time ****
      std::vector<double> time() const;
      void setTime(const std::vector<double>& time);


      // **** seed ****
      std::vector<int> seed() const;
      void setSeed(const std::vector<int>& seed);
    };
    
  }
}

