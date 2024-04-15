#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeNoiseGaussMarkovForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    Satellite SV ID.
    /// Process int    Gauss-Markov Process number (0 or 1)
    /// Enabled bool   If true, Gauss-Markov process is enabled
    /// Sigma   double Standard devition in meters [0..5000]
    /// Time    double Time constant [1..2000]
    /// Seed    int    Random seed
    ///

    class GetPseudorangeNoiseGaussMarkovForSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseGaussMarkovForSVResult> GetPseudorangeNoiseGaussMarkovForSVResultPtr;
    
    
    class GetPseudorangeNoiseGaussMarkovForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeNoiseGaussMarkovForSVResult();

      GetPseudorangeNoiseGaussMarkovForSVResult(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);

      GetPseudorangeNoiseGaussMarkovForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);

      static GetPseudorangeNoiseGaussMarkovForSVResultPtr create(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);

      static GetPseudorangeNoiseGaussMarkovForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);
      static GetPseudorangeNoiseGaussMarkovForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** process ****
      int process() const;
      void setProcess(int process);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** sigma ****
      double sigma() const;
      void setSigma(double sigma);


      // **** time ****
      double time() const;
      void setTime(double time);


      // **** seed ****
      int seed() const;
      void setSeed(int seed);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseGaussMarkovForSVResult);
  }
}

