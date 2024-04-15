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
    /// Result of GetSVAntennaModelForEachSV.
    ///
    /// Name              Type         Description
    /// ----------------- ------------ -----------------------------------------------------------------------------------------------------
    /// System            string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetSVAntennaModelForEachSVResult;
    typedef std::shared_ptr<GetSVAntennaModelForEachSVResult> GetSVAntennaModelForEachSVResultPtr;
    
    
    class GetSVAntennaModelForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVAntennaModelForEachSVResult();

      GetSVAntennaModelForEachSVResult(const std::string& system, const std::vector<std::string>& antennaModelNames);

      GetSVAntennaModelForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaModelNames);

      static GetSVAntennaModelForEachSVResultPtr create(const std::string& system, const std::vector<std::string>& antennaModelNames);

      static GetSVAntennaModelForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaModelNames);
      static GetSVAntennaModelForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaModelNames ****
      std::vector<std::string> antennaModelNames() const;
      void setAntennaModelNames(const std::vector<std::string>& antennaModelNames);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVAntennaModelForEachSVResult);
  }
}

