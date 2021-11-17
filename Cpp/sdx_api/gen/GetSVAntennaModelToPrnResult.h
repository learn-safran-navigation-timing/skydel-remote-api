#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVAntennaModelToPrn.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------------------------------------------------------------------
    /// Prn              int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// System           string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// AntennaModelName string SV antenna model name
    ///

    class GetSVAntennaModelToPrnResult;
    typedef std::shared_ptr<GetSVAntennaModelToPrnResult> GetSVAntennaModelToPrnResultPtr;
    
    
    class GetSVAntennaModelToPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelToPrnResult();

      GetSVAntennaModelToPrnResult(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& antennaModelName);
  
      static GetSVAntennaModelToPrnResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& antennaModelName);
      static GetSVAntennaModelToPrnResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);
    };
  }
}

