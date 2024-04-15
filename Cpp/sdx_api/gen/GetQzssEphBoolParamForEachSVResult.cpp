
#include "GetQzssEphBoolParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSVResult::CmdName = "GetQzssEphBoolParamForEachSVResult";
    const char* const GetQzssEphBoolParamForEachSVResult::Documentation = "Result of GetQzssEphBoolParamForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphBoolParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphBoolParamForEachSVResult);


    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForEachSVResult::GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetQzssEphBoolParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }


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
