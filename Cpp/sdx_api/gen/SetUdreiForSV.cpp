
#include "gen/SetUdreiForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetUdreiForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetUdreiForSV::CmdName = "SetUdreiForSV";
    const char* const SetUdreiForSV::Documentation = "Set the UDREI value transmitted by SBAS for the satellite of the specified constellation.";

    REGISTER_COMMAND_FACTORY(SetUdreiForSV);


    SetUdreiForSV::SetUdreiForSV()
      : CommandBase(CmdName)
    {}

    SetUdreiForSV::SetUdreiForSV(const std::string& system, int svId, int udrei)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setUdrei(udrei);
    }

    SetUdreiForSVPtr SetUdreiForSV::create(const std::string& system, int svId, int udrei)
    {
      return std::make_shared<SetUdreiForSV>(system, svId, udrei);
    }

    SetUdreiForSVPtr SetUdreiForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetUdreiForSV>(ptr);
    }

    bool SetUdreiForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Udrei"])
        ;

    }

    std::string SetUdreiForSV::documentation() const { return Documentation; }


    int SetUdreiForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string SetUdreiForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetUdreiForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetUdreiForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetUdreiForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetUdreiForSV::udrei() const
    {
      return parse_json<int>::parse(m_values["Udrei"]);
    }

    void SetUdreiForSV::setUdrei(int udrei)
    {
      m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
