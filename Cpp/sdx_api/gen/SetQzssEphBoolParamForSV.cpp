
#include "SetQzssEphBoolParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphBoolParamForSV::CmdName = "SetQzssEphBoolParamForSV";
    const char* const SetQzssEphBoolParamForSV::Documentation = "Please note the command SetQzssEphBoolParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various boolean parameters in the QZSS ephemeris\n"
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
      "Val         bool            Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssEphBoolParamForSV::TargetId = "";

    const char* const SetQzssEphBoolParamForSV::Deprecated = "Please note the command SetQzssEphBoolParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssEphBoolParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssEphBoolParamForSV);


    SetQzssEphBoolParamForSV::SetQzssEphBoolParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssEphBoolParamForSV::SetQzssEphBoolParamForSV(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphBoolParamForSVPtr SetQzssEphBoolParamForSV::create(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphBoolParamForSV>(svId, paramName, val, dataSetName);
    }

    SetQzssEphBoolParamForSVPtr SetQzssEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphBoolParamForSV>(ptr);
    }

    bool SetQzssEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphBoolParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssEphBoolParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetQzssEphBoolParamForSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetQzssEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssEphBoolParamForSV::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetQzssEphBoolParamForSV::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssEphBoolParamForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphBoolParamForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
