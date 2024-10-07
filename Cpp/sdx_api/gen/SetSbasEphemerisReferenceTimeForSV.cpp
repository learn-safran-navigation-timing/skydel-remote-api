
#include "SetSbasEphemerisReferenceTimeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasEphemerisReferenceTimeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasEphemerisReferenceTimeForSV::CmdName = "SetSbasEphemerisReferenceTimeForSV";
    const char* const SetSbasEphemerisReferenceTimeForSV::Documentation = "Set the ephemeris reference time for a SBAS satellite.\n"
      "\n"
      "Name Type     Description\n"
      "---- -------- ---------------------------------------------------------------\n"
      "SvId int      The satellite's SV ID.\n"
      "Time datetime GPS date and time (it is the GPS time expressed in UTC format).";
    const char* const SetSbasEphemerisReferenceTimeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasEphemerisReferenceTimeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasEphemerisReferenceTimeForSV);


    SetSbasEphemerisReferenceTimeForSV::SetSbasEphemerisReferenceTimeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasEphemerisReferenceTimeForSV::SetSbasEphemerisReferenceTimeForSV(int svId, const Sdx::DateTime& time)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setTime(time);
    }

    SetSbasEphemerisReferenceTimeForSVPtr SetSbasEphemerisReferenceTimeForSV::create(int svId, const Sdx::DateTime& time)
    {
      return std::make_shared<SetSbasEphemerisReferenceTimeForSV>(svId, time);
    }

    SetSbasEphemerisReferenceTimeForSVPtr SetSbasEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasEphemerisReferenceTimeForSV>(ptr);
    }

    bool SetSbasEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string SetSbasEphemerisReferenceTimeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasEphemerisReferenceTimeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Time"}; 
      return names; 
    }


    int SetSbasEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSbasEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime SetSbasEphemerisReferenceTimeForSV::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void SetSbasEphemerisReferenceTimeForSV::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
