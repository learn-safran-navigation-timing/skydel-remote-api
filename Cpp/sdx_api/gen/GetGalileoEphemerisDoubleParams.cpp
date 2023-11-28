
#include "gen/GetGalileoEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoEphemerisDoubleParams::CmdName = "GetGalileoEphemerisDoubleParams";
    const char* const GetGalileoEphemerisDoubleParams::Documentation = "Please note the command GetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use GetGalileoEphDoubleParamForEachSV.\n\nPlease note the command GetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet Galileo ephemeris parameter value for all satellites";

    const char* const GetGalileoEphemerisDoubleParams::Deprecated = "Please note the command GetGalileoEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetGalileoEphemerisDoubleParams);


    GetGalileoEphemerisDoubleParams::GetGalileoEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    GetGalileoEphemerisDoubleParams::GetGalileoEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGalileoEphemerisDoubleParamsPtr GetGalileoEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetGalileoEphemerisDoubleParamsPtr GetGalileoEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoEphemerisDoubleParams>(ptr);
    }

    bool GetGalileoEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoEphemerisDoubleParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetGalileoEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetGalileoEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGalileoEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGalileoEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
