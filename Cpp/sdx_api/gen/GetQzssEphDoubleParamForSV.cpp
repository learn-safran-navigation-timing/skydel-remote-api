
#include "GetQzssEphDoubleParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForSV::CmdName = "GetQzssEphDoubleParamForSV";
    const char* const GetQzssEphDoubleParamForSV::Documentation = "Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
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
    const char* const GetQzssEphDoubleParamForSV::TargetId = "";

    const char* const GetQzssEphDoubleParamForSV::Deprecated = "Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphDoubleParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphDoubleParamForSV);


    GetQzssEphDoubleParamForSV::GetQzssEphDoubleParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphDoubleParamForSV::GetQzssEphDoubleParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphDoubleParamForSVPtr GetQzssEphDoubleParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForSV>(svId, paramName, dataSetName);
    }

    GetQzssEphDoubleParamForSVPtr GetQzssEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForSV>(ptr);
    }

    bool GetQzssEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphDoubleParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphDoubleParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetQzssEphDoubleParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetQzssEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphDoubleParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphDoubleParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
