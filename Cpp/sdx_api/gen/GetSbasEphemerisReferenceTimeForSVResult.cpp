
#include "GetSbasEphemerisReferenceTimeForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasEphemerisReferenceTimeForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasEphemerisReferenceTimeForSVResult::CmdName = "GetSbasEphemerisReferenceTimeForSVResult";
    const char* const GetSbasEphemerisReferenceTimeForSVResult::Documentation = "Result of GetSbasEphemerisReferenceTimeForSV.\n"
      "\n"
      "Name Type     Description\n"
      "---- -------- ---------------------------------------------------------------\n"
      "SvId int      The satellite's SV ID.\n"
      "Time datetime GPS date and time (it is the GPS time expressed in UTC format).";
    const char* const GetSbasEphemerisReferenceTimeForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasEphemerisReferenceTimeForSVResult);


    GetSbasEphemerisReferenceTimeForSVResult::GetSbasEphemerisReferenceTimeForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasEphemerisReferenceTimeForSVResult::GetSbasEphemerisReferenceTimeForSVResult(int svId, const Sdx::DateTime& time)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setTime(time);
    }

    GetSbasEphemerisReferenceTimeForSVResult::GetSbasEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setTime(time);
    }


    GetSbasEphemerisReferenceTimeForSVResultPtr GetSbasEphemerisReferenceTimeForSVResult::create(int svId, const Sdx::DateTime& time)
    {
      return std::make_shared<GetSbasEphemerisReferenceTimeForSVResult>(svId, time);
    }

    GetSbasEphemerisReferenceTimeForSVResultPtr GetSbasEphemerisReferenceTimeForSVResult::create(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time)
    {
      return std::make_shared<GetSbasEphemerisReferenceTimeForSVResult>(relatedCommand, svId, time);
    }

    GetSbasEphemerisReferenceTimeForSVResultPtr GetSbasEphemerisReferenceTimeForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasEphemerisReferenceTimeForSVResult>(ptr);
    }

    bool GetSbasEphemerisReferenceTimeForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Time"])
        ;

    }

    std::string GetSbasEphemerisReferenceTimeForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasEphemerisReferenceTimeForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Time"}; 
      return names; 
    }


    int GetSbasEphemerisReferenceTimeForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSbasEphemerisReferenceTimeForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime GetSbasEphemerisReferenceTimeForSVResult::time() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Time"]);
    }

    void GetSbasEphemerisReferenceTimeForSVResult::setTime(const Sdx::DateTime& time)
    {
      m_values.AddMember("Time", parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
