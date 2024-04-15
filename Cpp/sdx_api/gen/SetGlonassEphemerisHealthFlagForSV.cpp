
#include "SetGlonassEphemerisHealthFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassEphemerisHealthFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassEphemerisHealthFlagForSV::CmdName = "SetGlonassEphemerisHealthFlagForSV";
    const char* const SetGlonassEphemerisHealthFlagForSV::Documentation = "Set GLONASS satellite Ephemeris Health Flag Bn(ln)\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- --------------------------------------\n"
      "SvId   int  The satellite's SV ID 1..24\n"
      "Health bool Status, false = OK, true = Malfunction";
    const char* const SetGlonassEphemerisHealthFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGlonassEphemerisHealthFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGlonassEphemerisHealthFlagForSV);


    SetGlonassEphemerisHealthFlagForSV::SetGlonassEphemerisHealthFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGlonassEphemerisHealthFlagForSV::SetGlonassEphemerisHealthFlagForSV(int svId, bool health)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
    }

    SetGlonassEphemerisHealthFlagForSVPtr SetGlonassEphemerisHealthFlagForSV::create(int svId, bool health)
    {
      return std::make_shared<SetGlonassEphemerisHealthFlagForSV>(svId, health);
    }

    SetGlonassEphemerisHealthFlagForSVPtr SetGlonassEphemerisHealthFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassEphemerisHealthFlagForSV>(ptr);
    }

    bool SetGlonassEphemerisHealthFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetGlonassEphemerisHealthFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGlonassEphemerisHealthFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health"}; 
      return names; 
    }


    int SetGlonassEphemerisHealthFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGlonassEphemerisHealthFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGlonassEphemerisHealthFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGlonassEphemerisHealthFlagForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGlonassEphemerisHealthFlagForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
