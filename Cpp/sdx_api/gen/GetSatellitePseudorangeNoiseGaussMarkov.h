#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSatellitePseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use GetPseudorangeNoiseGaussMarkovForSV.
    /// 
    /// Get the satellite pseudorange noise Gauss-Markov process attributes.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Process int    Gauss-Markov Process number (0 or 1)
    ///

    class GetSatellitePseudorangeNoiseGaussMarkov;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseGaussMarkov> GetSatellitePseudorangeNoiseGaussMarkovPtr;
    
    
    class GetSatellitePseudorangeNoiseGaussMarkov : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseGaussMarkov();

      GetSatellitePseudorangeNoiseGaussMarkov(const std::string& system, int prn, int process);
  
      static GetSatellitePseudorangeNoiseGaussMarkovPtr create(const std::string& system, int prn, int process);
      static GetSatellitePseudorangeNoiseGaussMarkovPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** process ****
      int process() const;
      void setProcess(int process);
    };
  }
}

