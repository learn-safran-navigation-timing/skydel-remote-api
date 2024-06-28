
#include "GetWFAntennaElementOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementOffset::CmdName = "GetWFAntennaElementOffset";
    const char* const GetWFAntennaElementOffset::Documentation = "Please note the command GetWFAntennaElementOffset is deprecated since 23.11. You may use GetVehicleAntennaOffset.\n"
      "\n"
      "Get the WF antenna offset infos for this element.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------\n"
      "Element int  One-based index for element in antenna.";
    const char* const GetWFAntennaElementOffset::TargetId = "";

    const char* const GetWFAntennaElementOffset::Deprecated = "Please note the command GetWFAntennaElementOffset is deprecated since 23.11. You may use GetVehicleAntennaOffset.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaElementOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaElementOffset);


    GetWFAntennaElementOffset::GetWFAntennaElementOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetWFAntennaElementOffset::GetWFAntennaElementOffset(int element)
      : CommandBase(CmdName, TargetId)
    {

      setElement(element);
    }

    GetWFAntennaElementOffsetPtr GetWFAntennaElementOffset::create(int element)
    {
      return std::make_shared<GetWFAntennaElementOffset>(element);
    }

    GetWFAntennaElementOffsetPtr GetWFAntennaElementOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementOffset>(ptr);
    }

    bool GetWFAntennaElementOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetWFAntennaElementOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element"}; 
      return names; 
    }

    std::optional<std::string> GetWFAntennaElementOffset::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetWFAntennaElementOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetWFAntennaElementOffset::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementOffset::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
