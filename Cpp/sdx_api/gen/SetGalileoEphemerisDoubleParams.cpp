
#include "SetGalileoEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoEphemerisDoubleParams::CmdName = "SetGalileoEphemerisDoubleParams";
    const char* const SetGalileoEphemerisDoubleParams::Documentation = "Please note the command SetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use SetGalileoEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command SetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set Galileo ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGalileoEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGalileoEphemerisDoubleParams::TargetId = "";

    const char* const SetGalileoEphemerisDoubleParams::Deprecated = "Please note the command SetGalileoEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoEphemerisDoubleParams);


    SetGalileoEphemerisDoubleParams::SetGalileoEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoEphemerisDoubleParams::SetGalileoEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGalileoEphemerisDoubleParamsPtr SetGalileoEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetGalileoEphemerisDoubleParamsPtr SetGalileoEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoEphemerisDoubleParams>(ptr);
    }

    bool SetGalileoEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGalileoEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetGalileoEphemerisDoubleParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetGalileoEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGalileoEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGalileoEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGalileoEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGalileoEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGalileoEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoEphemerisDoubleParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
