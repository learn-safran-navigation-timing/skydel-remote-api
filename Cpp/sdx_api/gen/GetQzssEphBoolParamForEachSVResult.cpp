
#include "gen/GetQzssEphBoolParamForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSVResult::CmdName = "GetQzssEphBoolParamForEachSVResult";
    const char* const GetQzssEphBoolParamForEachSVResult::Documentation = "Result of GetQzssEphBoolParamForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetQzssEphBoolParamForEachSVResult);


    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetQzssEphBoolParamForEachSVResultPtr GetQzssEphBoolParamForEachSVResult::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetQzssEphBoolParamForEachSVResultPtr GetQzssEphBoolParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetQzssEphBoolParamForEachSVResultPtr GetQzssEphBoolParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSVResult>(ptr);
    }

    bool GetQzssEphBoolParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphBoolParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetQzssEphBoolParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetQzssEphBoolParamForEachSVResult::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void GetQzssEphBoolParamForEachSVResult::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphBoolParamForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphBoolParamForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
