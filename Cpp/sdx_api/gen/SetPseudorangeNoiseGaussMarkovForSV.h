#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite pseudorange noise Gauss-Markov process attributes.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    Satellite SV ID.
    /// Process int    Gauss-Markov Process number (0 or 1)
    /// Enabled bool   If true, Gauss-Markov process is enabled
    /// Sigma   double Standard devition in meters [0..5000]
    /// Time    double Time constant [1..2000]
    /// Seed    int    Random seed
    ///

    class SetPseudorangeNoiseGaussMarkovForSV;
    typedef std::shared_ptr<SetPseudorangeNoiseGaussMarkovForSV> SetPseudorangeNoiseGaussMarkovForSVPtr;
    
    
    class SetPseudorangeNoiseGaussMarkovForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPseudorangeNoiseGaussMarkovForSV();

      SetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);

      static SetPseudorangeNoiseGaussMarkovForSVPtr create(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed);
      static SetPseudorangeNoiseGaussMarkovForSVPtr dynamicCast(CommandBasePtr ptr);
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
    
  }
}

