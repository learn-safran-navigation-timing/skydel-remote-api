
#include "IsWFAntennaElementEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsWFAntennaElementEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsWFAntennaElementEnabled::CmdName = "IsWFAntennaElementEnabled";
    const char* const IsWFAntennaElementEnabled::Documentation = "Please note the command IsWFAntennaElementEnabled is deprecated since 23.11. You may use GetWFElement.\n"
      "\n"
      "Get whether an antenna element is enabled or disabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------\n"
      "Element int  One-based index for element in antenna.";
    const char* const IsWFAntennaElementEnabled::TargetId = "";

    const char* const IsWFAntennaElementEnabled::Deprecated = "Please note the command IsWFAntennaElementEnabled is deprecated since 23.11. You may use GetWFElement.";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsWFAntennaElementEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsWFAntennaElementEnabled);


    IsWFAntennaElementEnabled::IsWFAntennaElementEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsWFAntennaElementEnabled::IsWFAntennaElementEnabled(int element)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsWFAntennaElementEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element"}; 
      return names; 
    }

    Sdx::optional<std::string> IsWFAntennaElementEnabled::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


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
