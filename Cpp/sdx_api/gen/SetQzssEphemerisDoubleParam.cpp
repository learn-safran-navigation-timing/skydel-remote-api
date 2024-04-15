
#include "SetQzssEphemerisDoubleParam.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisDoubleParam::CmdName = "SetQzssEphemerisDoubleParam";
    const char* const SetQzssEphemerisDoubleParam::Documentation = "Please note the command SetQzssEphemerisDoubleParam is deprecated since 21.3. You may use SetQzssEphDoubleParamForSV.\n"
      "\n"
      "Please note the command SetQzssEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various parameters in the QZSS ephemeris.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)\n"
      "ParamName   string          In meters:  \"Crs\", \"Crc\"\n"
      "                            In radians: \"Cis\", \"Cic\", \"Cus\", \"Cuc\"\n"
      "                            In seconds: \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
      "Val         double          Parameter value (see ParamName above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssEphemerisDoubleParam::TargetId = "";

    const char* const SetQzssEphemerisDoubleParam::Deprecated = "Please note the command SetQzssEphemerisDoubleParam is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssEphemerisDoubleParam);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssEphemerisDoubleParam);


    SetQzssEphemerisDoubleParam::SetQzssEphemerisDoubleParam()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssEphemerisDoubleParam::SetQzssEphemerisDoubleParam(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphemerisDoubleParamPtr SetQzssEphemerisDoubleParam::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphemerisDoubleParam>(svId, paramName, val, dataSetName);
    }

    SetQzssEphemerisDoubleParamPtr SetQzssEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisDoubleParam>(ptr);
    }

    bool SetQzssEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphemerisDoubleParam::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssEphemerisDoubleParam::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetQzssEphemerisDoubleParam::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetQzssEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetQzssEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphemerisDoubleParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
