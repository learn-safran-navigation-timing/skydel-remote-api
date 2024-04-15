
#include "SetGpsEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisDoubleParams::CmdName = "SetGpsEphemerisDoubleParams";
    const char* const SetGpsEphemerisDoubleParams::Documentation = "Please note the command SetGpsEphemerisDoubleParams is deprecated since 21.3. You may use SetGpsEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command SetGpsEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set GPS ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsEphemerisDoubleParams::TargetId = "";

    const char* const SetGpsEphemerisDoubleParams::Deprecated = "Please note the command SetGpsEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsEphemerisDoubleParams);


    SetGpsEphemerisDoubleParams::SetGpsEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsEphemerisDoubleParams::SetGpsEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphemerisDoubleParamsPtr SetGpsEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetGpsEphemerisDoubleParamsPtr SetGpsEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisDoubleParams>(ptr);
    }

    bool SetGpsEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetGpsEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetGpsEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
