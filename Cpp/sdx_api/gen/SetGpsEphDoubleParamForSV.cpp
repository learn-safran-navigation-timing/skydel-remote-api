
#include "SetGpsEphDoubleParamForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphDoubleParamForSV::CmdName = "SetGpsEphDoubleParamForSV";
    const char* const SetGpsEphDoubleParamForSV::Documentation = "Please note the command SetGpsEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various parameters in the GPS ephemeris\n"
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
      "  \"Tgd\"             sec\n"
      "  \"IscL1Ca\"         sec\n"
      "  \"IscL2C\"          sec\n"
      "  \"IscL5I5\"         sec\n"
      "  \"IscL5Q5\"         sec\n"
      "  \"IscL1CP\"         sec\n"
      "  \"IscL1CD\"         sec\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         double          Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsEphDoubleParamForSV::TargetId = "";

    const char* const SetGpsEphDoubleParamForSV::Deprecated = "Please note the command SetGpsEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsEphDoubleParamForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsEphDoubleParamForSV);


    SetGpsEphDoubleParamForSV::SetGpsEphDoubleParamForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsEphDoubleParamForSV::SetGpsEphDoubleParamForSV(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphDoubleParamForSVPtr SetGpsEphDoubleParamForSV::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphDoubleParamForSV>(svId, paramName, val, dataSetName);
    }

    SetGpsEphDoubleParamForSVPtr SetGpsEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphDoubleParamForSV>(ptr);
    }

    bool SetGpsEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphDoubleParamForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsEphDoubleParamForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetGpsEphDoubleParamForSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetGpsEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGpsEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetGpsEphDoubleParamForSV::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetGpsEphDoubleParamForSV::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphDoubleParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphDoubleParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
