
#include "GetBeiDouEphBoolParamForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphBoolParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphBoolParamForSVResult::CmdName = "GetBeiDouEphBoolParamForSVResult";
    const char* const GetBeiDouEphBoolParamForSVResult::Documentation = "Result of GetBeiDouEphBoolParamForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         bool            Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphBoolParamForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphBoolParamForSVResult);


    GetBeiDouEphBoolParamForSVResult::GetBeiDouEphBoolParamForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetBeiDouEphBoolParamForSVResult::GetBeiDouEphBoolParamForSVResult(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphBoolParamForSVResult::GetBeiDouEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetBeiDouEphBoolParamForSVResultPtr GetBeiDouEphBoolParamForSVResult::create(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetBeiDouEphBoolParamForSVResultPtr GetBeiDouEphBoolParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphBoolParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetBeiDouEphBoolParamForSVResultPtr GetBeiDouEphBoolParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForSVResult>(ptr);
    }

    bool GetBeiDouEphBoolParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphBoolParamForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphBoolParamForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouEphBoolParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphBoolParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouEphBoolParamForSVResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetBeiDouEphBoolParamForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphBoolParamForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
