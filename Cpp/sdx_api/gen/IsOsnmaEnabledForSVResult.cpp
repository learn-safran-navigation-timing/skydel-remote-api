
#include "IsOsnmaEnabledForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsOsnmaEnabledForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsOsnmaEnabledForSVResult::CmdName = "IsOsnmaEnabledForSVResult";
    const char* const IsOsnmaEnabledForSVResult::Documentation = "Result of IsOsnmaEnabledForSV.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------------------\n"
      "SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).\n"
      "Enabled bool OSNMA is enabled when value is True.";
    const char* const IsOsnmaEnabledForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsOsnmaEnabledForSVResult);


    IsOsnmaEnabledForSVResult::IsOsnmaEnabledForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsOsnmaEnabledForSVResult::IsOsnmaEnabledForSVResult(int svId, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setEnabled(enabled);
    }

    IsOsnmaEnabledForSVResult::IsOsnmaEnabledForSVResult(CommandBasePtr relatedCommand, int svId, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setEnabled(enabled);
    }


    IsOsnmaEnabledForSVResultPtr IsOsnmaEnabledForSVResult::create(int svId, bool enabled)
    {
      return std::make_shared<IsOsnmaEnabledForSVResult>(svId, enabled);
    }

    IsOsnmaEnabledForSVResultPtr IsOsnmaEnabledForSVResult::create(CommandBasePtr relatedCommand, int svId, bool enabled)
    {
      return std::make_shared<IsOsnmaEnabledForSVResult>(relatedCommand, svId, enabled);
    }

    IsOsnmaEnabledForSVResultPtr IsOsnmaEnabledForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsOsnmaEnabledForSVResult>(ptr);
    }

    bool IsOsnmaEnabledForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsOsnmaEnabledForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsOsnmaEnabledForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Enabled"}; 
      return names; 
    }


    int IsOsnmaEnabledForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsOsnmaEnabledForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsOsnmaEnabledForSVResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsOsnmaEnabledForSVResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
