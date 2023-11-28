
#include "gen/GetGpsEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisDoubleParams::CmdName = "GetGpsEphemerisDoubleParams";
    const char* const GetGpsEphemerisDoubleParams::Documentation = "Please note the command GetGpsEphemerisDoubleParams is deprecated since 21.3. You may use GetGpsEphDoubleParamForEachSV.\n\nPlease note the command GetGpsEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet GPS ephemeris parameter value for all satellites";

    const char* const GetGpsEphemerisDoubleParams::Deprecated = "Please note the command GetGpsEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetGpsEphemerisDoubleParams);


    GetGpsEphemerisDoubleParams::GetGpsEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    GetGpsEphemerisDoubleParams::GetGpsEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphemerisDoubleParamsPtr GetGpsEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetGpsEphemerisDoubleParamsPtr GetGpsEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisDoubleParams>(ptr);
    }

    bool GetGpsEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphemerisDoubleParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetGpsEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetGpsEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
