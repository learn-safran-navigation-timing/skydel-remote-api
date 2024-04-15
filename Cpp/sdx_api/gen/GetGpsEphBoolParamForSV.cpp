
#include "GetGpsEphBoolParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForSV::CmdName = "GetGpsEphBoolParamForSV";
    const char* const GetGpsEphBoolParamForSV::Documentation = "Please note the command GetGpsEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get various boolean parameters in the GPS ephemeris\n"
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
      "SvId        int             Satellite SV ID 1..32, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsEphBoolParamForSV::TargetId = "";

    const char* const GetGpsEphBoolParamForSV::Deprecated = "Please note the command GetGpsEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsEphBoolParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsEphBoolParamForSV);


    GetGpsEphBoolParamForSV::GetGpsEphBoolParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGpsEphBoolParamForSV::GetGpsEphBoolParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForSVPtr GetGpsEphBoolParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForSV>(svId, paramName, dataSetName);
    }

    GetGpsEphBoolParamForSVPtr GetGpsEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForSV>(ptr);
    }

    bool GetGpsEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsEphBoolParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetGpsEphBoolParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetGpsEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
