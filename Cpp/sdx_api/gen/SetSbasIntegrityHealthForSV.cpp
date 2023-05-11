
#include "gen/SetSbasIntegrityHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasIntegrityHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasIntegrityHealthForSV::CmdName = "SetSbasIntegrityHealthForSV";
    const char* const SetSbasIntegrityHealthForSV::Documentation = "Apply integrity flag for a SBAS satellite";

    REGISTER_COMMAND_FACTORY(SetSbasIntegrityHealthForSV);


    SetSbasIntegrityHealthForSV::SetSbasIntegrityHealthForSV()
      : CommandBase(CmdName)
    {}

    SetSbasIntegrityHealthForSV::SetSbasIntegrityHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetSbasIntegrityHealthForSVPtr SetSbasIntegrityHealthForSV::create(int svId, bool health)
    {
      return std::make_shared<SetSbasIntegrityHealthForSV>(svId, health);
    }

    SetSbasIntegrityHealthForSVPtr SetSbasIntegrityHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasIntegrityHealthForSV>(ptr);
    }

    bool SetSbasIntegrityHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasIntegrityHealthForSV::documentation() const { return Documentation; }


    int SetSbasIntegrityHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasIntegrityHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasIntegrityHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasIntegrityHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasIntegrityHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
