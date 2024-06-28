
#include "GetGpsEphBoolParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForEachSVResult::CmdName = "GetGpsEphBoolParamForEachSVResult";
    const char* const GetGpsEphBoolParamForEachSVResult::Documentation = "Result of GetGpsEphBoolParamForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphBoolParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphBoolParamForEachSVResult);


    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForEachSVResult::GetGpsEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetGpsEphBoolParamForEachSVResultPtr GetGpsEphBoolParamForEachSVResult::create(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetGpsEphBoolParamForEachSVResultPtr GetGpsEphBoolParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphBoolParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetGpsEphBoolParamForEachSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForEachSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
