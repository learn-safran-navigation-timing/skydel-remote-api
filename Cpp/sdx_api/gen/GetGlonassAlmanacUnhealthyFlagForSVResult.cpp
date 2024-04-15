
#include "GetGlonassAlmanacUnhealthyFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassAlmanacUnhealthyFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassAlmanacUnhealthyFlagForSVResult::CmdName = "GetGlonassAlmanacUnhealthyFlagForSVResult";
    const char* const GetGlonassAlmanacUnhealthyFlagForSVResult::Documentation = "Result of GetGlonassAlmanacUnhealthyFlagForSV.\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- ----------------------------------------------------------\n"
      "SvId   int  The satellite's SV ID 1..24\n"
      "Health bool Status, false = Non-operability, true = Operability (Good)";
    const char* const GetGlonassAlmanacUnhealthyFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassAlmanacUnhealthyFlagForSVResult);


    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult(int svId, bool health)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
    }

    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetGlonassAlmanacUnhealthyFlagForSVResultPtr GetGlonassAlmanacUnhealthyFlagForSVResult::create(int svId, bool health)
    {
      return std::make_shared<GetGlonassAlmanacUnhealthyFlagForSVResult>(svId, health);
    }

    GetGlonassAlmanacUnhealthyFlagForSVResultPtr GetGlonassAlmanacUnhealthyFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return std::make_shared<GetGlonassAlmanacUnhealthyFlagForSVResult>(relatedCommand, svId, health);
    }

    GetGlonassAlmanacUnhealthyFlagForSVResultPtr GetGlonassAlmanacUnhealthyFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassAlmanacUnhealthyFlagForSVResult>(ptr);
    }

    bool GetGlonassAlmanacUnhealthyFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGlonassAlmanacUnhealthyFlagForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassAlmanacUnhealthyFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health"}; 
      return names; 
    }


    int GetGlonassAlmanacUnhealthyFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassAlmanacUnhealthyFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGlonassAlmanacUnhealthyFlagForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGlonassAlmanacUnhealthyFlagForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
