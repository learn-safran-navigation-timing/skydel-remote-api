
#include "GetQzssEphemerisBoolParam.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisBoolParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisBoolParam::CmdName = "GetQzssEphemerisBoolParam";
    const char* const GetQzssEphemerisBoolParam::Documentation = "Please note the command GetQzssEphemerisBoolParam is deprecated since 21.3. You may use GetQzssEphBoolParamForSV.\n"
      "\n"
      "Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get various boolean parameters in the QZSS ephemeris\n"
      "\n"
      "  ParamName\n"
      "\"IscL1CaAvailable\"\n"
      "\"IscL2CAvailable\"\n"
      "\"IscL5I5Available\"\n"
      "\"IscL5Q5Available\"\n"
      "\"IscL1CPAvailable\"\n"
      "\"IscL1CDAvailable\"\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphemerisBoolParam::TargetId = "";

    const char* const GetQzssEphemerisBoolParam::Deprecated = "Please note the command GetQzssEphemerisBoolParam is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphemerisBoolParam);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphemerisBoolParam);


    GetQzssEphemerisBoolParam::GetQzssEphemerisBoolParam()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphemerisBoolParam::GetQzssEphemerisBoolParam(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisBoolParamPtr GetQzssEphemerisBoolParam::create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisBoolParam>(svId, paramName, dataSetName);
    }

    GetQzssEphemerisBoolParamPtr GetQzssEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisBoolParam>(ptr);
    }

    bool GetQzssEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisBoolParam::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphemerisBoolParam::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetQzssEphemerisBoolParam::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphemerisBoolParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisBoolParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphemerisBoolParam::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisBoolParam::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
