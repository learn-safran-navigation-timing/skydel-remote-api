
#include "gen/GetQzssEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisDoubleParams::CmdName = "GetQzssEphemerisDoubleParams";
    const char* const GetQzssEphemerisDoubleParams::Documentation = "Please note the command GetQzssEphemerisDoubleParams is deprecated since 21.3. You may use GetQzssEphDoubleParamForEachSV.\n\nPlease note the command GetQzssEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet QZSS ephemeris parameter value for all satellites";

    const char* const GetQzssEphemerisDoubleParams::Deprecated = "Please note the command GetQzssEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetQzssEphemerisDoubleParams);


    GetQzssEphemerisDoubleParams::GetQzssEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    GetQzssEphemerisDoubleParams::GetQzssEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisDoubleParamsPtr GetQzssEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetQzssEphemerisDoubleParamsPtr GetQzssEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisDoubleParams>(ptr);
    }

    bool GetQzssEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisDoubleParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetQzssEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
