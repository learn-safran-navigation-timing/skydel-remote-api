
#include "gen/IsWFAntennaElementEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsWFAntennaElementEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsWFAntennaElementEnabled::CmdName = "IsWFAntennaElementEnabled";
    const char* const IsWFAntennaElementEnabled::Documentation = "Get whether an antenna element is enabled or disabled.";

    REGISTER_COMMAND_FACTORY(IsWFAntennaElementEnabled);


    IsWFAntennaElementEnabled::IsWFAntennaElementEnabled()
      : CommandBase(CmdName)
    {}

    IsWFAntennaElementEnabled::IsWFAntennaElementEnabled(int element)
      : CommandBase(CmdName)
    {

      setElement(element);
    }

    IsWFAntennaElementEnabledPtr IsWFAntennaElementEnabled::create(int element)
    {
      return std::make_shared<IsWFAntennaElementEnabled>(element);
    }

    IsWFAntennaElementEnabledPtr IsWFAntennaElementEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsWFAntennaElementEnabled>(ptr);
    }

    bool IsWFAntennaElementEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string IsWFAntennaElementEnabled::documentation() const { return Documentation; }


    int IsWFAntennaElementEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsWFAntennaElementEnabled::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void IsWFAntennaElementEnabled::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
