
#include "GetBeiDouEphDoubleParamForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphDoubleParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphDoubleParamForSVResult::CmdName = "GetBeiDouEphDoubleParamForSVResult";
    const char* const GetBeiDouEphDoubleParamForSVResult::Documentation = "Result of GetBeiDouEphDoubleParamForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         double          Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetBeiDouEphDoubleParamForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetBeiDouEphDoubleParamForSVResult);


    GetBeiDouEphDoubleParamForSVResult::GetBeiDouEphDoubleParamForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetBeiDouEphDoubleParamForSVResult::GetBeiDouEphDoubleParamForSVResult(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphDoubleParamForSVResult::GetBeiDouEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetBeiDouEphDoubleParamForSVResultPtr GetBeiDouEphDoubleParamForSVResult::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphDoubleParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetBeiDouEphDoubleParamForSVResultPtr GetBeiDouEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetBeiDouEphDoubleParamForSVResultPtr GetBeiDouEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphDoubleParamForSVResult>(ptr);
    }

    bool GetBeiDouEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphDoubleParamForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetBeiDouEphDoubleParamForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int GetBeiDouEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetBeiDouEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphDoubleParamForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphDoubleParamForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
