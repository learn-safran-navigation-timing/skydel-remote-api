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
    /// Result of GetSbasMonitoredSystems.
    ///
    /// Name    Type         Description
    /// ------- ------------ ------------------------------------------------------------------------------------
    /// Systems array string A list containing the name of monitored systems, only "GPS" and "SBAS" are supported
    ///

    class GetSbasMonitoredSystemsResult;
    typedef std::shared_ptr<GetSbasMonitoredSystemsResult> GetSbasMonitoredSystemsResultPtr;
    
    
    class GetSbasMonitoredSystemsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasMonitoredSystemsResult();

      GetSbasMonitoredSystemsResult(const std::vector<std::string>& systems);

      GetSbasMonitoredSystemsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& systems);

      static GetSbasMonitoredSystemsResultPtr create(const std::vector<std::string>& systems);

      static GetSbasMonitoredSystemsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& systems);
      static GetSbasMonitoredSystemsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** systems ****
      std::vector<std::string> systems() const;
      void setSystems(const std::vector<std::string>& systems);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSbasMonitoredSystemsResult);
  }
}

