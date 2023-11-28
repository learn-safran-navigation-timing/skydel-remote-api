
#include "gen/GetWFAntennaElementOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementOffset::CmdName = "GetWFAntennaElementOffset";
    const char* const GetWFAntennaElementOffset::Documentation = "Please note the command GetWFAntennaElementOffset is deprecated since 23.11. You may use GetVehicleAntennaOffset.\n\nGet the WF antenna offset infos for this element.";

    const char* const GetWFAntennaElementOffset::Deprecated = "Please note the command GetWFAntennaElementOffset is deprecated since 23.11. You may use GetVehicleAntennaOffset.";

    REGISTER_COMMAND_FACTORY(GetWFAntennaElementOffset);


    GetWFAntennaElementOffset::GetWFAntennaElementOffset()
      : CommandBase(CmdName)
    {}

    GetWFAntennaElementOffset::GetWFAntennaElementOffset(int element)
      : CommandBase(CmdName)
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

    Sdx::optional<std::string> GetWFAntennaElementOffset::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


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
