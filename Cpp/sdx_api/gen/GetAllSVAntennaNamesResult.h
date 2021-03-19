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
    /// Result of GetAllSVNames
    ///
    /// Name         Type         Description
    /// ------------ ------------ ----------------------------------------------------------------
    /// System       string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// AntennaNames array string A list of antenna model names.
    ///

    class GetAllSVAntennaNamesResult;
    typedef std::shared_ptr<GetAllSVAntennaNamesResult> GetAllSVAntennaNamesResultPtr;
    
    
    class GetAllSVAntennaNamesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSVAntennaNamesResult();

      GetAllSVAntennaNamesResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames);
  
      static GetAllSVAntennaNamesResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames);
      static GetAllSVAntennaNamesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaNames ****
      std::vector<std::string> antennaNames() const;
      void setAntennaNames(const std::vector<std::string>& antennaNames);
    };
  }
}

