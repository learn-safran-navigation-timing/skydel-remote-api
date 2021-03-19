#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVAntennaModelForAllSat
    ///
    /// Name              Type         Description
    /// ----------------- ------------ --------------------------------------------------------------------------------------------------------------------------------------------------
    /// AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => PRN 1, index 1 => PRN 2, etc and index 0 => 120, index 1 => 121, etc for SBAS)
    /// System            string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetSVAntennaModelForAllSatResult;
    typedef std::shared_ptr<GetSVAntennaModelForAllSatResult> GetSVAntennaModelForAllSatResultPtr;
    
    
    class GetSVAntennaModelForAllSatResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelForAllSatResult();

      GetSVAntennaModelForAllSatResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaModelNames, const std::string& system);
  
      static GetSVAntennaModelForAllSatResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaModelNames, const std::string& system);
      static GetSVAntennaModelForAllSatResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** antennaModelNames ****
      std::vector<std::string> antennaModelNames() const;
      void setAntennaModelNames(const std::vector<std::string>& antennaModelNames);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

