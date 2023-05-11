
#include "gen/SetSbasCorrectionsHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasCorrectionsHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasCorrectionsHealthForSV::CmdName = "SetSbasCorrectionsHealthForSV";
    const char* const SetSbasCorrectionsHealthForSV::Documentation = "Apply correction flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasCorrectionsHealthForSV);


    SetSbasCorrectionsHealthForSV::SetSbasCorrectionsHealthForSV()
      : CommandBase(CmdName)
    {}

    SetSbasCorrectionsHealthForSV::SetSbasCorrectionsHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetSbasCorrectionsHealthForSVPtr SetSbasCorrectionsHealthForSV::create(int svId, bool health)
    {
      return std::make_shared<SetSbasCorrectionsHealthForSV>(svId, health);
    }

    SetSbasCorrectionsHealthForSVPtr SetSbasCorrectionsHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasCorrectionsHealthForSV>(ptr);
    }

    bool SetSbasCorrectionsHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasCorrectionsHealthForSV::documentation() const { return Documentation; }


    int SetSbasCorrectionsHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasCorrectionsHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasCorrectionsHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasCorrectionsHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasCorrectionsHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
