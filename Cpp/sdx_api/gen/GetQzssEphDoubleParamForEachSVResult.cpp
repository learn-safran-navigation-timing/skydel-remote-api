
#include "GetQzssEphDoubleParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForEachSVResult::CmdName = "GetQzssEphDoubleParamForEachSVResult";
    const char* const GetQzssEphDoubleParamForEachSVResult::Documentation = "Result of GetQzssEphDoubleParamForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphDoubleParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphDoubleParamForEachSVResult);


    GetQzssEphDoubleParamForEachSVResult::GetQzssEphDoubleParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssEphDoubleParamForEachSVResult::GetQzssEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetQzssEphDoubleParamForEachSVResult::GetQzssEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetQzssEphDoubleParamForEachSVResultPtr GetQzssEphDoubleParamForEachSVResult::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetQzssEphDoubleParamForEachSVResultPtr GetQzssEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetQzssEphDoubleParamForEachSVResultPtr GetQzssEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetQzssEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphDoubleParamForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphDoubleParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    std::string GetQzssEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetQzssEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetQzssEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphDoubleParamForEachSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphDoubleParamForEachSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
