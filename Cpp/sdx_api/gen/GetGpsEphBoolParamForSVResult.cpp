
#include "gen/GetGpsEphBoolParamForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForSVResult::CmdName = "GetGpsEphBoolParamForSVResult";
    const char* const GetGpsEphBoolParamForSVResult::Documentation = "Result of GetGpsEphBoolParamForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsEphBoolParamForSVResult);


    GetGpsEphBoolParamForSVResult::GetGpsEphBoolParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphBoolParamForSVResult::GetGpsEphBoolParamForSVResult(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForSVResult::GetGpsEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGpsEphBoolParamForSVResultPtr GetGpsEphBoolParamForSVResult::create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetGpsEphBoolParamForSVResultPtr GetGpsEphBoolParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetGpsEphBoolParamForSVResultPtr GetGpsEphBoolParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForSVResult>(ptr);
    }

    bool GetGpsEphBoolParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForSVResult::documentation() const { return Documentation; }


    int GetGpsEphBoolParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsEphBoolParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphBoolParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsEphBoolParamForSVResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetGpsEphBoolParamForSVResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphBoolParamForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
