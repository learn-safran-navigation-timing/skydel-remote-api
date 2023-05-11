
#include "gen/SetSbasRangingHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasRangingHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasRangingHealthForSV::CmdName = "SetSbasRangingHealthForSV";
    const char* const SetSbasRangingHealthForSV::Documentation = "Apply ranging flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasRangingHealthForSV);


    SetSbasRangingHealthForSV::SetSbasRangingHealthForSV()
      : CommandBase(CmdName)
    {}

    SetSbasRangingHealthForSV::SetSbasRangingHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetSbasRangingHealthForSVPtr SetSbasRangingHealthForSV::create(int svId, bool health)
    {
      return std::make_shared<SetSbasRangingHealthForSV>(svId, health);
    }

    SetSbasRangingHealthForSVPtr SetSbasRangingHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasRangingHealthForSV>(ptr);
    }

    bool SetSbasRangingHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasRangingHealthForSV::documentation() const { return Documentation; }


    int SetSbasRangingHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasRangingHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasRangingHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasRangingHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasRangingHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
