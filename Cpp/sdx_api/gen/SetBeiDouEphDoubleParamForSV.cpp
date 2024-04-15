
#include "SetBeiDouEphDoubleParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphDoubleParamForSV::CmdName = "SetBeiDouEphDoubleParamForSV";
    const char* const SetBeiDouEphDoubleParamForSV::Documentation = "Please note the command SetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various parameters in the BeiDou ephemeris\n"
      "\n"
      "  ParamName         Unit\n"
      "  \"ClockBias\"       sec\n"
      "  \"ClockDrift\"      sec/sec\n"
      "  \"ClockDriftRate\"  sec/sec^2\n"
      "  \"Crs\"             meter\n"
      "  \"Crc\"             meter\n"
      "  \"Cis\"             rad\n"
      "  \"Cic\"             rad\n"
      "  \"Cus\"             rad\n"
      "  \"Cuc\"             rad\n"
      "  \"DeltaN\"          rad/sec\n"
      "  \"M0\"              rad\n"
      "  \"Eccentricity\"    -\n"
      "  \"SqrtA\"           sqrt(meter)\n"
      "  \"BigOmega\"        rad\n"
      "  \"I0\"              rad\n"
      "  \"LittleOmega\"     rad\n"
      "  \"BigOmegaDot\"     rad/sec\n"
      "  \"Idot\"            rad/sec\n"
      "  \"Accuracy\"        meter\n"
      "  \"Adot\"            meters/sec\n"
      "  \"DeltaN0dot\"      rad/sec^2\n"
      "  \"Tgd1\"            sec\n"
      "  \"Tgd2\"            sec\n"
      "  \"TgdB1Cp\"         sec\n"
      "  \"TgdB2Ap\"         sec\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         double          Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouEphDoubleParamForSV::TargetId = "";

    const char* const SetBeiDouEphDoubleParamForSV::Deprecated = "Please note the command SetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouEphDoubleParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouEphDoubleParamForSV);


    SetBeiDouEphDoubleParamForSV::SetBeiDouEphDoubleParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouEphDoubleParamForSV::SetBeiDouEphDoubleParamForSV(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphDoubleParamForSVPtr SetBeiDouEphDoubleParamForSV::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphDoubleParamForSV>(svId, paramName, val, dataSetName);
    }

    SetBeiDouEphDoubleParamForSVPtr SetBeiDouEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphDoubleParamForSV>(ptr);
    }

    bool SetBeiDouEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphDoubleParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouEphDoubleParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetBeiDouEphDoubleParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetBeiDouEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetBeiDouEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetBeiDouEphDoubleParamForSV::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetBeiDouEphDoubleParamForSV::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphDoubleParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphDoubleParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
