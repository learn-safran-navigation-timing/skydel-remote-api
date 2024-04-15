
#include "GetQzssEphBoolParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForSV::CmdName = "GetQzssEphBoolParamForSV";
    const char* const GetQzssEphBoolParamForSV::Documentation = "Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
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
    const char* const GetQzssEphBoolParamForSV::TargetId = "";

    const char* const GetQzssEphBoolParamForSV::Deprecated = "Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssEphBoolParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssEphBoolParamForSV);


    GetQzssEphBoolParamForSV::GetQzssEphBoolParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssEphBoolParamForSV::GetQzssEphBoolParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForSVPtr GetQzssEphBoolParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForSV>(svId, paramName, dataSetName);
    }

    GetQzssEphBoolParamForSVPtr GetQzssEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForSV>(ptr);
    }

    bool GetQzssEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphBoolParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssEphBoolParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetQzssEphBoolParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetQzssEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
