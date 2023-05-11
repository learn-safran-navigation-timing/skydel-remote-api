#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeNoiseGaussMarkovForEachSV.
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

    class GetPseudorangeNoiseGaussMarkovForEachSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseGaussMarkovForEachSVResult> GetPseudorangeNoiseGaussMarkovForEachSVResultPtr;
    typedef GetPseudorangeNoiseGaussMarkovForEachSVResult GetAllSatellitesPseudorangeNoiseGaussMarkovResult;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseGaussMarkovResult> GetAllSatellitesPseudorangeNoiseGaussMarkovResultPtr;
    
    class GetPseudorangeNoiseGaussMarkovForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseGaussMarkovForEachSVResult();

      GetPseudorangeNoiseGaussMarkovForEachSVResult(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);

      GetPseudorangeNoiseGaussMarkovForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);

      static GetPseudorangeNoiseGaussMarkovForEachSVResultPtr create(const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);

      static GetPseudorangeNoiseGaussMarkovForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int process, const std::vector<bool>& enabled, const std::vector<double>& sigma, const std::vector<double>& time, const std::vector<int>& seed);
      static GetPseudorangeNoiseGaussMarkovForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetPseudorangeNoiseGaussMarkovForEachSVResult);
  }
}

