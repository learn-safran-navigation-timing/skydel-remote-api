#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllSVAntennaNames.
    ///
    /// Name         Type         Description
    /// ------------ ------------ --------------------------------------------------------------------------
    /// System       string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// AntennaNames array string A list of antenna model names.
    ///

    class GetAllSVAntennaNamesResult;
    typedef std::shared_ptr<GetAllSVAntennaNamesResult> GetAllSVAntennaNamesResultPtr;
    
    
    class GetAllSVAntennaNamesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllSVAntennaNamesResult();

      GetAllSVAntennaNamesResult(const std::string& system, const std::vector<std::string>& antennaNames);

      GetAllSVAntennaNamesResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames);

      static GetAllSVAntennaNamesResultPtr create(const std::string& system, const std::vector<std::string>& antennaNames);

      static GetAllSVAntennaNamesResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames);
      static GetAllSVAntennaNamesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaNames ****
      std::vector<std::string> antennaNames() const;
      void setAntennaNames(const std::vector<std::string>& antennaNames);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSVAntennaNamesResult);
  }
}

