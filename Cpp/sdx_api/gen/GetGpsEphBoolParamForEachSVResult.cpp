
#include "gen/GetGpsEphBoolParamForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForEachSVResult::CmdName = "GetGpsEphBoolParamForEachSVResult";
    const char* const GetGpsEphBoolParamForEachSVResult::Documentation = "Result of GetGpsEphBoolParamForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsEphBoolParamForEachSVResult);


    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGpsEphBoolParamForEachSVResultPtr GetGpsEphBoolParamForEachSVResult::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetGpsEphBoolParamForEachSVResultPtr GetGpsEphBoolParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetGpsEphBoolParamForEachSVResultPtr GetGpsEphBoolParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForEachSVResult>(ptr);
    }

    bool GetGpsEphBoolParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetGpsEphBoolParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetGpsEphBoolParamForEachSVResult::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void GetGpsEphBoolParamForEachSVResult::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphBoolParamForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
