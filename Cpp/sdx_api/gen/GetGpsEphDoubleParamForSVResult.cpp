
#include "gen/GetGpsEphDoubleParamForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphDoubleParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphDoubleParamForSVResult::CmdName = "GetGpsEphDoubleParamForSVResult";
    const char* const GetGpsEphDoubleParamForSVResult::Documentation = "Result of GetGpsEphDoubleParamForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsEphDoubleParamForSVResult);


    GetGpsEphDoubleParamForSVResult::GetGpsEphDoubleParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphDoubleParamForSVResult::GetGpsEphDoubleParamForSVResult(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGpsEphDoubleParamForSVResult::GetGpsEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGpsEphDoubleParamForSVResultPtr GetGpsEphDoubleParamForSVResult::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphDoubleParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetGpsEphDoubleParamForSVResultPtr GetGpsEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetGpsEphDoubleParamForSVResultPtr GetGpsEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForSVResult>(ptr);
    }

    bool GetGpsEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphDoubleParamForSVResult::documentation() const { return Documentation; }


    int GetGpsEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetGpsEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetGpsEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphDoubleParamForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphDoubleParamForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
