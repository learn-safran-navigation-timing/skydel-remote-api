
#include "gen/GetBeiDouEphBoolParamForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForEachSVResult::CmdName = "GetBeiDouEphBoolParamForEachSVResult";
    const char* const GetBeiDouEphBoolParamForEachSVResult::Documentation = "Result of GetBeiDouEphBoolParamForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetBeiDouEphBoolParamForEachSVResult);


    GetBeiDouEphBoolParamForEachSVResult::GetBeiDouEphBoolParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouEphBoolParamForEachSVResult::GetBeiDouEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphBoolParamForEachSVResult::GetBeiDouEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetBeiDouEphBoolParamForEachSVResultPtr GetBeiDouEphBoolParamForEachSVResult::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetBeiDouEphBoolParamForEachSVResultPtr GetBeiDouEphBoolParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetBeiDouEphBoolParamForEachSVResultPtr GetBeiDouEphBoolParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForEachSVResult>(ptr);
    }

    bool GetBeiDouEphBoolParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphBoolParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetBeiDouEphBoolParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetBeiDouEphBoolParamForEachSVResult::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void GetBeiDouEphBoolParamForEachSVResult::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphBoolParamForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphBoolParamForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
