
#include "gen/GetGlonassEphDoubleParamForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphDoubleParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphDoubleParamForSVResult::CmdName = "GetGlonassEphDoubleParamForSVResult";
    const char* const GetGlonassEphDoubleParamForSVResult::Documentation = "Result of GetGlonassEphDoubleParamForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGlonassEphDoubleParamForSVResult);


    GetGlonassEphDoubleParamForSVResult::GetGlonassEphDoubleParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetGlonassEphDoubleParamForSVResult::GetGlonassEphDoubleParamForSVResult(int svId, const std::string& paramName, double val)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }

    GetGlonassEphDoubleParamForSVResult::GetGlonassEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }


    GetGlonassEphDoubleParamForSVResultPtr GetGlonassEphDoubleParamForSVResult::create(int svId, const std::string& paramName, double val)
    {
      return std::make_shared<GetGlonassEphDoubleParamForSVResult>(svId, paramName, val);
    }

    GetGlonassEphDoubleParamForSVResultPtr GetGlonassEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
    {
      return std::make_shared<GetGlonassEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val);
    }

    GetGlonassEphDoubleParamForSVResultPtr GetGlonassEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForSVResult>(ptr);
    }

    bool GetGlonassEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGlonassEphDoubleParamForSVResult::documentation() const { return Documentation; }


    int GetGlonassEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGlonassEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGlonassEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGlonassEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
