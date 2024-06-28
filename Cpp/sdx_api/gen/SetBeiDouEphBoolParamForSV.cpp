
#include "SetBeiDouEphBoolParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphBoolParamForSV::CmdName = "SetBeiDouEphBoolParamForSV";
    const char* const SetBeiDouEphBoolParamForSV::Documentation = "Please note the command SetBeiDouEphBoolParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various boolean parameters in the BeiDou ephemeris\n"
      "\n"
      "  ParamName\n"
      "\"IscB1CdAvailable\"\n"
      "\"IscB2adAvailable\"\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         bool            Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouEphBoolParamForSV::TargetId = "";

    const char* const SetBeiDouEphBoolParamForSV::Deprecated = "Please note the command SetBeiDouEphBoolParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouEphBoolParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouEphBoolParamForSV);


    SetBeiDouEphBoolParamForSV::SetBeiDouEphBoolParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouEphBoolParamForSV::SetBeiDouEphBoolParamForSV(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphBoolParamForSVPtr SetBeiDouEphBoolParamForSV::create(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphBoolParamForSV>(svId, paramName, val, dataSetName);
    }

    SetBeiDouEphBoolParamForSVPtr SetBeiDouEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphBoolParamForSV>(ptr);
    }

    bool SetBeiDouEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphBoolParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouEphBoolParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetBeiDouEphBoolParamForSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetBeiDouEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetBeiDouEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouEphBoolParamForSV::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetBeiDouEphBoolParamForSV::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouEphBoolParamForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphBoolParamForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
