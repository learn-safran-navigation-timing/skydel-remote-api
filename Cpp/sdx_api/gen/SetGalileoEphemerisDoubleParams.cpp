
#include "gen/SetGalileoEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoEphemerisDoubleParams::CmdName = "SetGalileoEphemerisDoubleParams";
    const char* const SetGalileoEphemerisDoubleParams::Documentation = "Please note the command SetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use SetGalileoEphDoubleParamForEachSV.\n\nPlease note the command SetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n\nSet Galileo ephemeris parameter value for all satellites";

    const char* const SetGalileoEphemerisDoubleParams::Deprecated = "Please note the command SetGalileoEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(SetGalileoEphemerisDoubleParams);


    SetGalileoEphemerisDoubleParams::SetGalileoEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    SetGalileoEphemerisDoubleParams::SetGalileoEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGalileoEphemerisDoubleParamsPtr SetGalileoEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGalileoEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetGalileoEphemerisDoubleParamsPtr SetGalileoEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoEphemerisDoubleParams>(ptr);
    }

    bool SetGalileoEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGalileoEphemerisDoubleParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> SetGalileoEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetGalileoEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGalileoEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGalileoEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGalileoEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGalileoEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGalileoEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGalileoEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
