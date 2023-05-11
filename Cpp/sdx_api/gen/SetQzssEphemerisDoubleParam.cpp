
#include "gen/SetQzssEphemerisDoubleParam.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphemerisDoubleParam::CmdName = "SetQzssEphemerisDoubleParam";
    const char* const SetQzssEphemerisDoubleParam::Documentation = "Please note the command SetQzssEphemerisDoubleParam is deprecated since 21.3. You may use SetQzssEphDoubleParamForSV.\n\nSet various parameters in the QZSS ephemeris.";

    REGISTER_COMMAND_FACTORY(SetQzssEphemerisDoubleParam);


    SetQzssEphemerisDoubleParam::SetQzssEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    SetQzssEphemerisDoubleParam::SetQzssEphemerisDoubleParam(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphemerisDoubleParamPtr SetQzssEphemerisDoubleParam::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphemerisDoubleParam>(svId, paramName, val, dataSetName);
    }

    SetQzssEphemerisDoubleParamPtr SetQzssEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphemerisDoubleParam>(ptr);
    }

    bool SetQzssEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphemerisDoubleParam::documentation() const { return Documentation; }


    int SetQzssEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetQzssEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphemerisDoubleParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
