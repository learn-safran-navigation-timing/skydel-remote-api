
#include "SetBeiDouEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphemerisDoubleParams::CmdName = "SetBeiDouEphemerisDoubleParams";
    const char* const SetBeiDouEphemerisDoubleParams::Documentation = "Please note the command SetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use SetBeiDouEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command SetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set BeiDou ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouEphemerisDoubleParams::TargetId = "";

    const char* const SetBeiDouEphemerisDoubleParams::Deprecated = "Please note the command SetBeiDouEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouEphemerisDoubleParams);


    SetBeiDouEphemerisDoubleParams::SetBeiDouEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouEphemerisDoubleParams::SetBeiDouEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphemerisDoubleParamsPtr SetBeiDouEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetBeiDouEphemerisDoubleParamsPtr SetBeiDouEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphemerisDoubleParams>(ptr);
    }

    bool SetBeiDouEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetBeiDouEphemerisDoubleParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetBeiDouEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetBeiDouEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphemerisDoubleParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
