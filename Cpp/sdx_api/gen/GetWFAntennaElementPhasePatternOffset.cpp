
#include "gen/GetWFAntennaElementPhasePatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementPhasePatternOffset::CmdName = "GetWFAntennaElementPhasePatternOffset";
    const char* const GetWFAntennaElementPhasePatternOffset::Documentation = "Get WF Antenna phase pattern offset (in rad) for this element";

    REGISTER_COMMAND_FACTORY(GetWFAntennaElementPhasePatternOffset);


    GetWFAntennaElementPhasePatternOffset::GetWFAntennaElementPhasePatternOffset()
      : CommandBase(CmdName)
    {}

    GetWFAntennaElementPhasePatternOffset::GetWFAntennaElementPhasePatternOffset(int element)
      : CommandBase(CmdName)
    {

      setElement(element);
    }

    GetWFAntennaElementPhasePatternOffsetPtr GetWFAntennaElementPhasePatternOffset::create(int element)
    {
      return std::make_shared<GetWFAntennaElementPhasePatternOffset>(element);
    }

    GetWFAntennaElementPhasePatternOffsetPtr GetWFAntennaElementPhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementPhasePatternOffset>(ptr);
    }

    bool GetWFAntennaElementPhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementPhasePatternOffset::documentation() const { return Documentation; }


    int GetWFAntennaElementPhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetWFAntennaElementPhasePatternOffset::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementPhasePatternOffset::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
