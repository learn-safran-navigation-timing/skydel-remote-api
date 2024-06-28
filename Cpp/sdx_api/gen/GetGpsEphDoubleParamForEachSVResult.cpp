
#include "GetGpsEphDoubleParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphDoubleParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphDoubleParamForEachSVResult::CmdName = "GetGpsEphDoubleParamForEachSVResult";
    const char* const GetGpsEphDoubleParamForEachSVResult::Documentation = "Result of GetGpsEphDoubleParamForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphDoubleParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphDoubleParamForEachSVResult);


    GetGpsEphDoubleParamForEachSVResult::GetGpsEphDoubleParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsEphDoubleParamForEachSVResult::GetGpsEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGpsEphDoubleParamForEachSVResult::GetGpsEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGpsEphDoubleParamForEachSVResultPtr GetGpsEphDoubleParamForEachSVResult::create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphDoubleParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetGpsEphDoubleParamForEachSVResultPtr GetGpsEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphDoubleParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetGpsEphDoubleParamForEachSVResultPtr GetGpsEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetGpsEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphDoubleParamForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphDoubleParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    std::string GetGpsEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGpsEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetGpsEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetGpsEphDoubleParamForEachSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphDoubleParamForEachSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
