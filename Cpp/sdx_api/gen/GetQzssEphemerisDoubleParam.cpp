
#include "GetQzssEphemerisDoubleParam.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisDoubleParam::CmdName = "GetQzssEphemerisDoubleParam";
    const char* const GetQzssEphemerisDoubleParam::Documentation = "Please note the command GetQzssEphemerisDoubleParam is deprecated since 21.3. You may use GetQzssEphDoubleParamForSV.\n"
      "\n"
      "Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get various parameters in the QZSS ephemeris.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)\n"
      "ParamName   string          In meters:  \"Crs\", \"Crc\"\n"
      "                            In radians: \"Cis\", \"Cic\", \"Cus\", \"Cuc\"\n"
      "                            In seconds: \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssEphemerisDoubleParam::TargetId = "";

    const char* const GetQzssEphemerisDoubleParam::Deprecated = "Please note the command GetQzssEphemerisDoubleParam is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphemerisDoubleParam);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphemerisDoubleParam);


    GetQzssEphemerisDoubleParam::GetQzssEphemerisDoubleParam()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphemerisDoubleParam::GetQzssEphemerisDoubleParam(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisDoubleParamPtr GetQzssEphemerisDoubleParam::create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisDoubleParam>(svId, paramName, dataSetName);
    }

    GetQzssEphemerisDoubleParamPtr GetQzssEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisDoubleParam>(ptr);
    }

    bool GetQzssEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisDoubleParam::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphemerisDoubleParam::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> GetQzssEphemerisDoubleParam::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisDoubleParam::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
