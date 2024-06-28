
#include "GetQzssEphDoubleParamForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForSVResult::CmdName = "GetQzssEphDoubleParamForSVResult";
    const char* const GetQzssEphDoubleParamForSVResult::Documentation = "Result of GetQzssEphDoubleParamForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)\n"
      "ParamName   string          In meters:  \"Crs\", \"Crc\"\n"
      "                            In radians: \"Cis\", \"Cic\", \"Cus\", \"Cuc\"\n"
      "                            In seconds: \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
      "Val         double          Parameter value (see ParamName above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphDoubleParamForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphDoubleParamForSVResult);


    GetQzssEphDoubleParamForSVResult::GetQzssEphDoubleParamForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssEphDoubleParamForSVResult::GetQzssEphDoubleParamForSVResult(int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetQzssEphDoubleParamForSVResult::GetQzssEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetQzssEphDoubleParamForSVResultPtr GetQzssEphDoubleParamForSVResult::create(int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForSVResult>(svId, paramName, val, dataSetName);
    }

    GetQzssEphDoubleParamForSVResultPtr GetQzssEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
    }

    GetQzssEphDoubleParamForSVResultPtr GetQzssEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForSVResult>(ptr);
    }

    bool GetQzssEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphDoubleParamForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphDoubleParamForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    int GetQzssEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetQzssEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetQzssEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphDoubleParamForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphDoubleParamForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
