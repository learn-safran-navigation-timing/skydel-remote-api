
#include "gen/GetGlonassAlmanacUnhealthyFlagForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassAlmanacUnhealthyFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassAlmanacUnhealthyFlagForSVResult::CmdName = "GetGlonassAlmanacUnhealthyFlagForSVResult";
    const char* const GetGlonassAlmanacUnhealthyFlagForSVResult::Documentation = "Result of GetGlonassAlmanacUnhealthyFlagForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGlonassAlmanacUnhealthyFlagForSVResult);


    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult(int svId, bool health)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }

    GetGlonassAlmanacUnhealthyFlagForSVResult::GetGlonassAlmanacUnhealthyFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
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
