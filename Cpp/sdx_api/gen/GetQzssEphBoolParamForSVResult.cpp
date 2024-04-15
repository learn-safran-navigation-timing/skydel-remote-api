
#include "GetQzssEphBoolParamForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForSVResult::CmdName = "GetQzssEphBoolParamForSVResult";
    const char* const GetQzssEphBoolParamForSVResult::Documentation = "Result of GetQzssEphBoolParamForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         bool            Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphBoolParamForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphBoolParamForSVResult);


    GetQzssEphBoolParamForSVResult::GetQzssEphBoolParamForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssEphBoolParamForSVResult::GetQzssEphBoolParamForSVResult(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForSVResult::GetQzssEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetQzssEphBoolParamForSVResultPtr GetQzssEphBoolParamForSVResult::create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetQzssEphBoolParamForSVResultPtr GetQzssEphBoolParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetQzssEphBoolParamForSVResultPtr GetQzssEphBoolParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForSVResult>(ptr);
    }

    bool GetQzssEphBoolParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphBoolParamForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphBoolParamForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int GetQzssEphBoolParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphBoolParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphBoolParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssEphBoolParamForSVResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetQzssEphBoolParamForSVResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphBoolParamForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphBoolParamForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
