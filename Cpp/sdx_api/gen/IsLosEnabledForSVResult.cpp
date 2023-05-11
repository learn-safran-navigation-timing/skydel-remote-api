
#include "gen/IsLosEnabledForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsLosEnabledForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsLosEnabledForSVResult::CmdName = "IsLosEnabledForSVResult";
    const char* const IsLosEnabledForSVResult::Documentation = "Result of IsLosEnabledForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsLosEnabledForSVResult);


    IsLosEnabledForSVResult::IsLosEnabledForSVResult()
      : CommandResult(CmdName)
    {}

    IsLosEnabledForSVResult::IsLosEnabledForSVResult(const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }

    IsLosEnabledForSVResult::IsLosEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
    }


    IsLosEnabledForSVResultPtr IsLosEnabledForSVResult::create(const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsLosEnabledForSVResult>(system, svId, enabled);
    }

    IsLosEnabledForSVResultPtr IsLosEnabledForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
    {
      return std::make_shared<IsLosEnabledForSVResult>(relatedCommand, system, svId, enabled);
    }

    IsLosEnabledForSVResultPtr IsLosEnabledForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsLosEnabledForSVResult>(ptr);
    }

    bool IsLosEnabledForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsLosEnabledForSVResult::documentation() const { return Documentation; }


    std::string IsLosEnabledForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsLosEnabledForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsLosEnabledForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsLosEnabledForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsLosEnabledForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsLosEnabledForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
