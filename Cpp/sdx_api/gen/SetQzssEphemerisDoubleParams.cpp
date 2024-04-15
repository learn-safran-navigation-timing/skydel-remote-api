
#include "SetQzssEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisDoubleParams::CmdName = "SetQzssEphemerisDoubleParams";
    const char* const SetQzssEphemerisDoubleParams::Documentation = "Please note the command SetQzssEphemerisDoubleParams is deprecated since 21.3. You may use SetQzssEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command SetQzssEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set QZSS ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssEphemerisDoubleParams::TargetId = "";

    const char* const SetQzssEphemerisDoubleParams::Deprecated = "Please note the command SetQzssEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssEphemerisDoubleParams);


    SetQzssEphemerisDoubleParams::SetQzssEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssEphemerisDoubleParams::SetQzssEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphemerisDoubleParamsPtr SetQzssEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetQzssEphemerisDoubleParamsPtr SetQzssEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisDoubleParams>(ptr);
    }

    bool SetQzssEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetQzssEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetQzssEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetQzssEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetQzssEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
