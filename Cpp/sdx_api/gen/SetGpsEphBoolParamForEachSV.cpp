
#include "SetGpsEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphBoolParamForEachSV::CmdName = "SetGpsEphBoolParamForEachSV";
    const char* const SetGpsEphBoolParamForEachSV::Documentation = "Please note the command SetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set GPS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetGpsEphBoolParamForSV for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsEphBoolParamForEachSV::TargetId = "";

    const char* const SetGpsEphBoolParamForEachSV::Deprecated = "Please note the command SetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsEphBoolParamForEachSV);


    SetGpsEphBoolParamForEachSV::SetGpsEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsEphBoolParamForEachSV::SetGpsEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphBoolParamForEachSVPtr SetGpsEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphBoolParamForEachSV>(paramName, val, dataSetName);
    }

    SetGpsEphBoolParamForEachSVPtr SetGpsEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphBoolParamForEachSV>(ptr);
    }

    bool SetGpsEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetGpsEphBoolParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetGpsEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetGpsEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetGpsEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
