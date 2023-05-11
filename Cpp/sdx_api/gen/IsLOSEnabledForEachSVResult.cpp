
#include "gen/IsLOSEnabledForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLOSEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLOSEnabledForEachSVResult::CmdName = "IsLOSEnabledForEachSVResult";
    const char* const IsLOSEnabledForEachSVResult::Documentation = "Result of IsLOSEnabledForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLOSEnabledForEachSVResult);


    IsLOSEnabledForEachSVResult::IsLOSEnabledForEachSVResult()
      : CommandResult(CmdName)
    {}

    IsLOSEnabledForEachSVResult::IsLOSEnabledForEachSVResult(const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setEnabled(enabled);
    }

    IsLOSEnabledForEachSVResult::IsLOSEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
    }


    IsLOSEnabledForEachSVResultPtr IsLOSEnabledForEachSVResult::create(const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsLOSEnabledForEachSVResult>(system, enabled);
    }

    IsLOSEnabledForEachSVResultPtr IsLOSEnabledForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsLOSEnabledForEachSVResult>(relatedCommand, system, enabled);
    }

    IsLOSEnabledForEachSVResultPtr IsLOSEnabledForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLOSEnabledForEachSVResult>(ptr);
    }

    bool IsLOSEnabledForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLOSEnabledForEachSVResult::documentation() const { return Documentation; }


    std::string IsLOSEnabledForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLOSEnabledForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsLOSEnabledForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsLOSEnabledForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
