
#include "SetSbasServiceHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasServiceHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasServiceHealthForSV::CmdName = "SetSbasServiceHealthForSV";
    const char* const SetSbasServiceHealthForSV::Documentation = "Apply service provider for a satellite\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- ---------------------\n"
      "SvId   int  The satellite's SV ID\n"
      "Health int  The service provider";
    const char* const SetSbasServiceHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasServiceHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasServiceHealthForSV);


    SetSbasServiceHealthForSV::SetSbasServiceHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasServiceHealthForSV::SetSbasServiceHealthForSV(int svId, int health)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetSbasServiceHealthForSVPtr SetSbasServiceHealthForSV::create(int svId, int health)
    {
      return std::make_shared<SetSbasServiceHealthForSV>(svId, health);
    }

    SetSbasServiceHealthForSVPtr SetSbasServiceHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasServiceHealthForSV>(ptr);
    }

    bool SetSbasServiceHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasServiceHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasServiceHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health"}; 
      return names; 
    }


    int SetSbasServiceHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSbasServiceHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasServiceHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSbasServiceHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetSbasServiceHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
