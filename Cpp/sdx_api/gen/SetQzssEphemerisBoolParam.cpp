
#include "gen/SetQzssEphemerisBoolParam.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisBoolParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisBoolParam::CmdName = "SetQzssEphemerisBoolParam";
    const char* const SetQzssEphemerisBoolParam::Documentation = "Please note the command SetQzssEphemerisBoolParam is deprecated since 21.3. You may use SetQzssEphBoolParamForSV.\n\nPlease note the command SetQzssEphBoolParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n\nSet various boolean parameters in the QZSS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    const char* const SetQzssEphemerisBoolParam::Deprecated = "Please note the command SetQzssEphemerisBoolParam is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(SetQzssEphemerisBoolParam);


    SetQzssEphemerisBoolParam::SetQzssEphemerisBoolParam()
      : CommandBase(CmdName)
    {}

    SetQzssEphemerisBoolParam::SetQzssEphemerisBoolParam(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphemerisBoolParamPtr SetQzssEphemerisBoolParam::create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphemerisBoolParam>(svId, paramName, val, dataSetName);
    }

    SetQzssEphemerisBoolParamPtr SetQzssEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisBoolParam>(ptr);
    }

    bool SetQzssEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphemerisBoolParam::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetQzssEphemerisBoolParam::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetQzssEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphemerisBoolParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphemerisBoolParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssEphemerisBoolParam::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetQzssEphemerisBoolParam::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphemerisBoolParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphemerisBoolParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
