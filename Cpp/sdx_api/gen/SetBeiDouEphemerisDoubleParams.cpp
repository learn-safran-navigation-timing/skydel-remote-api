
#include "gen/SetBeiDouEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphemerisDoubleParams::CmdName = "SetBeiDouEphemerisDoubleParams";
    const char* const SetBeiDouEphemerisDoubleParams::Documentation = "Please note the command SetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use SetBeiDouEphDoubleParamForEachSV.\n\nSet BeiDou ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphemerisDoubleParams);


    SetBeiDouEphemerisDoubleParams::SetBeiDouEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphemerisDoubleParams::SetBeiDouEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphemerisDoubleParamsPtr SetBeiDouEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetBeiDouEphemerisDoubleParamsPtr SetBeiDouEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphemerisDoubleParams>(ptr);
    }

    bool SetBeiDouEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphemerisDoubleParams::documentation() const { return Documentation; }


    int SetBeiDouEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetBeiDouEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
