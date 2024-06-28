
#include "SetGpsEphemerisBoolParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisBoolParams::CmdName = "SetGpsEphemerisBoolParams";
    const char* const SetGpsEphemerisBoolParams::Documentation = "Please note the command SetGpsEphemerisBoolParams is deprecated since 21.3. You may use SetGpsEphBoolParamForEachSV.\n"
      "\n"
      "Please note the command SetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set GPS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsEphemerisBoolParams::TargetId = "";

    const char* const SetGpsEphemerisBoolParams::Deprecated = "Please note the command SetGpsEphemerisBoolParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsEphemerisBoolParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsEphemerisBoolParams);


    SetGpsEphemerisBoolParams::SetGpsEphemerisBoolParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsEphemerisBoolParams::SetGpsEphemerisBoolParams(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphemerisBoolParamsPtr SetGpsEphemerisBoolParams::create(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphemerisBoolParams>(paramName, val, dataSetName);
    }

    SetGpsEphemerisBoolParamsPtr SetGpsEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisBoolParams>(ptr);
    }

    bool SetGpsEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphemerisBoolParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsEphemerisBoolParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetGpsEphemerisBoolParams::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetGpsEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetGpsEphemerisBoolParams::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisBoolParams::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsEphemerisBoolParams::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphemerisBoolParams::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
