
#include "gen/SetQzssEphDoubleParamForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphDoubleParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphDoubleParamForSV::CmdName = "SetQzssEphDoubleParamForSV";
    const char* const SetQzssEphDoubleParamForSV::Documentation = "Set various parameters in the QZSS ephemeris.";

    REGISTER_COMMAND_FACTORY(SetQzssEphDoubleParamForSV);


    SetQzssEphDoubleParamForSV::SetQzssEphDoubleParamForSV()
      : CommandBase(CmdName)
    {}

    SetQzssEphDoubleParamForSV::SetQzssEphDoubleParamForSV(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetQzssEphDoubleParamForSVPtr SetQzssEphDoubleParamForSV::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssEphDoubleParamForSV>(svId, paramName, val, dataSetName);
    }

    SetQzssEphDoubleParamForSVPtr SetQzssEphDoubleParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphDoubleParamForSV>(ptr);
    }

    bool SetQzssEphDoubleParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssEphDoubleParamForSV::documentation() const { return Documentation; }


    int SetQzssEphDoubleParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetQzssEphDoubleParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssEphDoubleParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssEphDoubleParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphDoubleParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssEphDoubleParamForSV::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetQzssEphDoubleParamForSV::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssEphDoubleParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssEphDoubleParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
