
#include "IsWFAntennaElementEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsWFAntennaElementEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsWFAntennaElementEnabledResult::CmdName = "IsWFAntennaElementEnabledResult";
    const char* const IsWFAntennaElementEnabledResult::Documentation = "Result of IsWFAntennaElementEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -------------------------------------------------\n"
      "Element int  One-based index for element in antenna.\n"
      "Enabled bool If True, this antenna element will bil simulated.";
    const char* const IsWFAntennaElementEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsWFAntennaElementEnabledResult);


    IsWFAntennaElementEnabledResult::IsWFAntennaElementEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsWFAntennaElementEnabledResult::IsWFAntennaElementEnabledResult(int element, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setElement(element);
      setEnabled(enabled);
    }

    IsWFAntennaElementEnabledResult::IsWFAntennaElementEnabledResult(CommandBasePtr relatedCommand, int element, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setElement(element);
      setEnabled(enabled);
    }


    IsWFAntennaElementEnabledResultPtr IsWFAntennaElementEnabledResult::create(int element, bool enabled)
    {
      return std::make_shared<IsWFAntennaElementEnabledResult>(element, enabled);
    }

    IsWFAntennaElementEnabledResultPtr IsWFAntennaElementEnabledResult::create(CommandBasePtr relatedCommand, int element, bool enabled)
    {
      return std::make_shared<IsWFAntennaElementEnabledResult>(relatedCommand, element, enabled);
    }

    IsWFAntennaElementEnabledResultPtr IsWFAntennaElementEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsWFAntennaElementEnabledResult>(ptr);
    }

    bool IsWFAntennaElementEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsWFAntennaElementEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsWFAntennaElementEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element", "Enabled"}; 
      return names; 
    }


    int IsWFAntennaElementEnabledResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void IsWFAntennaElementEnabledResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsWFAntennaElementEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsWFAntennaElementEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
