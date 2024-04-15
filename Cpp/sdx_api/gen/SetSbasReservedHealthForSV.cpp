
#include "SetSbasReservedHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasReservedHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasReservedHealthForSV::CmdName = "SetSbasReservedHealthForSV";
    const char* const SetSbasReservedHealthForSV::Documentation = "Apply reserved flag for a SBAS satellite\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- ---------------------------\n"
      "SvId   int  The satellite's SV ID\n"
      "Health bool The reserved unhealthy flag";
    const char* const SetSbasReservedHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasReservedHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasReservedHealthForSV);


    SetSbasReservedHealthForSV::SetSbasReservedHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasReservedHealthForSV::SetSbasReservedHealthForSV(int svId, bool health)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetSbasReservedHealthForSVPtr SetSbasReservedHealthForSV::create(int svId, bool health)
    {
      return std::make_shared<SetSbasReservedHealthForSV>(svId, health);
    }

    SetSbasReservedHealthForSVPtr SetSbasReservedHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasReservedHealthForSV>(ptr);
    }

    bool SetSbasReservedHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetSbasReservedHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasReservedHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health"}; 
      return names; 
    }


    int SetSbasReservedHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetSbasReservedHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasReservedHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSbasReservedHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetSbasReservedHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
