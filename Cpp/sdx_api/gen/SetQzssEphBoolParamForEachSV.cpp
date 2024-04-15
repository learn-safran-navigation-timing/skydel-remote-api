
#include "SetQzssEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphBoolParamForEachSV::CmdName = "SetQzssEphBoolParamForEachSV";
    const char* const SetQzssEphBoolParamForEachSV::Documentation = "Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set QZSS ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssEphBoolParamForEachSV::TargetId = "";

    const char* const SetQzssEphBoolParamForEachSV::Deprecated = "Please note the command SetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssEphBoolParamForEachSV);


    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphBoolParamForEachSV>(paramName, val, dataSetName);
    }

    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphBoolParamForEachSV>(ptr);
    }

    bool SetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetQzssEphBoolParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetQzssEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetQzssEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
