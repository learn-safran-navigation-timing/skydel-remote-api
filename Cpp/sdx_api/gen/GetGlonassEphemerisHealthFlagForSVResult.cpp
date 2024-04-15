
#include "GetGlonassEphemerisHealthFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphemerisHealthFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphemerisHealthFlagForSVResult::CmdName = "GetGlonassEphemerisHealthFlagForSVResult";
    const char* const GetGlonassEphemerisHealthFlagForSVResult::Documentation = "Result of GetGlonassEphemerisHealthFlagForSV.\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- --------------------------------------\n"
      "SvId   int  The satellite's SV ID 1..24\n"
      "Health bool Status, false = OK, true = Malfunction";
    const char* const GetGlonassEphemerisHealthFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassEphemerisHealthFlagForSVResult);


    GetGlonassEphemerisHealthFlagForSVResult::GetGlonassEphemerisHealthFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGlonassEphemerisHealthFlagForSVResult::GetGlonassEphemerisHealthFlagForSVResult(int svId, bool health)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
    }

    GetGlonassEphemerisHealthFlagForSVResult::GetGlonassEphemerisHealthFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetGlonassEphemerisHealthFlagForSVResultPtr GetGlonassEphemerisHealthFlagForSVResult::create(int svId, bool health)
    {
      return std::make_shared<GetGlonassEphemerisHealthFlagForSVResult>(svId, health);
    }

    GetGlonassEphemerisHealthFlagForSVResultPtr GetGlonassEphemerisHealthFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return std::make_shared<GetGlonassEphemerisHealthFlagForSVResult>(relatedCommand, svId, health);
    }

    GetGlonassEphemerisHealthFlagForSVResultPtr GetGlonassEphemerisHealthFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphemerisHealthFlagForSVResult>(ptr);
    }

    bool GetGlonassEphemerisHealthFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGlonassEphemerisHealthFlagForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassEphemerisHealthFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health"}; 
      return names; 
    }


    int GetGlonassEphemerisHealthFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassEphemerisHealthFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGlonassEphemerisHealthFlagForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGlonassEphemerisHealthFlagForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
