
#include "gen/GetSbasEphParamsForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasEphParamsForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasEphParamsForSVResult::CmdName = "GetSbasEphParamsForSVResult";
    const char* const GetSbasEphParamsForSVResult::Documentation = "Result of GetSbasEphParamsForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSbasEphParamsForSVResult);


    GetSbasEphParamsForSVResult::GetSbasEphParamsForSVResult()
      : CommandResult(CmdName)
    {}

    GetSbasEphParamsForSVResult::GetSbasEphParamsForSVResult(int svId, const std::map<std::string, double>& paramValueDict)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setParamValueDict(paramValueDict);
    }

    GetSbasEphParamsForSVResult::GetSbasEphParamsForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamValueDict(paramValueDict);
    }


    GetSbasEphParamsForSVResultPtr GetSbasEphParamsForSVResult::create(int svId, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<GetSbasEphParamsForSVResult>(svId, paramValueDict);
    }

    GetSbasEphParamsForSVResultPtr GetSbasEphParamsForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict)
    {
      return std::make_shared<GetSbasEphParamsForSVResult>(relatedCommand, svId, paramValueDict);
    }

    GetSbasEphParamsForSVResultPtr GetSbasEphParamsForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasEphParamsForSVResult>(ptr);
    }

    bool GetSbasEphParamsForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
        ;

    }

    std::string GetSbasEphParamsForSVResult::documentation() const { return Documentation; }


    int GetSbasEphParamsForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSbasEphParamsForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> GetSbasEphParamsForSVResult::paramValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
    }

    void GetSbasEphParamsForSVResult::setParamValueDict(const std::map<std::string, double>& paramValueDict)
    {
      m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
