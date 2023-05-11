
#include "gen/SetGpsEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphemerisDoubleParams::CmdName = "SetGpsEphemerisDoubleParams";
    const char* const SetGpsEphemerisDoubleParams::Documentation = "Please note the command SetGpsEphemerisDoubleParams is deprecated since 21.3. You may use SetGpsEphDoubleParamForEachSV.\n\nSet GPS ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetGpsEphemerisDoubleParams);


    SetGpsEphemerisDoubleParams::SetGpsEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    SetGpsEphemerisDoubleParams::SetGpsEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphemerisDoubleParamsPtr SetGpsEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetGpsEphemerisDoubleParamsPtr SetGpsEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphemerisDoubleParams>(ptr);
    }

    bool SetGpsEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphemerisDoubleParams::documentation() const { return Documentation; }


    int SetGpsEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGpsEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGpsEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
