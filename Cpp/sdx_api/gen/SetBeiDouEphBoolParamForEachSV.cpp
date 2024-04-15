
#include "SetBeiDouEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphBoolParamForEachSV::CmdName = "SetBeiDouEphBoolParamForEachSV";
    const char* const SetBeiDouEphBoolParamForEachSV::Documentation = "Please note the command SetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set BeiDou ephemeris boolean parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphBoolParamForSV for accepted names\n"
      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouEphBoolParamForEachSV::TargetId = "";

    const char* const SetBeiDouEphBoolParamForEachSV::Deprecated = "Please note the command SetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouEphBoolParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouEphBoolParamForEachSV);


    SetBeiDouEphBoolParamForEachSV::SetBeiDouEphBoolParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouEphBoolParamForEachSV::SetBeiDouEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphBoolParamForEachSVPtr SetBeiDouEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphBoolParamForEachSV>(paramName, val, dataSetName);
    }

    SetBeiDouEphBoolParamForEachSVPtr SetBeiDouEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphBoolParamForEachSV>(ptr);
    }

    bool SetBeiDouEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphBoolParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouEphBoolParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetBeiDouEphBoolParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetBeiDouEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetBeiDouEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
