
#include "gen/SetWFAntennaElementEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetWFAntennaElementEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetWFAntennaElementEnabled::CmdName = "SetWFAntennaElementEnabled";
    const char* const SetWFAntennaElementEnabled::Documentation = "Set WF antenna element enabled or disabled. A disabled antenna element is not simulated at all.";

    REGISTER_COMMAND_FACTORY(SetWFAntennaElementEnabled);


    SetWFAntennaElementEnabled::SetWFAntennaElementEnabled()
      : CommandBase(CmdName)
    {}

    SetWFAntennaElementEnabled::SetWFAntennaElementEnabled(int element, bool enabled)
      : CommandBase(CmdName)
    {

      setElement(element);
      setEnabled(enabled);
    }

    SetWFAntennaElementEnabledPtr SetWFAntennaElementEnabled::create(int element, bool enabled)
    {
      return std::make_shared<SetWFAntennaElementEnabled>(element, enabled);
    }

    SetWFAntennaElementEnabledPtr SetWFAntennaElementEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetWFAntennaElementEnabled>(ptr);
    }

    bool SetWFAntennaElementEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string SetWFAntennaElementEnabled::documentation() const { return Documentation; }


    int SetWFAntennaElementEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetWFAntennaElementEnabled::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void SetWFAntennaElementEnabled::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetWFAntennaElementEnabled::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetWFAntennaElementEnabled::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
