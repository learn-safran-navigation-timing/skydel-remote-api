
#include "SetBeiDouEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphDoubleParamForEachSV::CmdName = "SetBeiDouEphDoubleParamForEachSV";
    const char* const SetBeiDouEphDoubleParamForEachSV::Documentation = "Please note the command SetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set BeiDou ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetBeiDouEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouEphDoubleParamForEachSV::TargetId = "";

    const char* const SetBeiDouEphDoubleParamForEachSV::Deprecated = "Please note the command SetBeiDouEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouEphDoubleParamForEachSV);


    SetBeiDouEphDoubleParamForEachSV::SetBeiDouEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouEphDoubleParamForEachSV::SetBeiDouEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphDoubleParamForEachSVPtr SetBeiDouEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphDoubleParamForEachSV>(paramName, val, dataSetName);
    }

    SetBeiDouEphDoubleParamForEachSVPtr SetBeiDouEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphDoubleParamForEachSV>(ptr);
    }

    bool SetBeiDouEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    std::optional<std::string> SetBeiDouEphDoubleParamForEachSV::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int SetBeiDouEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetBeiDouEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphDoubleParamForEachSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
