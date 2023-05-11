
#include "gen/GetGpsEphemerisBoolParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphemerisBoolParams::CmdName = "GetGpsEphemerisBoolParams";
    const char* const GetGpsEphemerisBoolParams::Documentation = "Please note the command GetGpsEphemerisBoolParams is deprecated since 21.3. You may use GetGpsEphBoolParamForEachSV.\n\nGet GPS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetGpsEphemerisBoolParams);


    GetGpsEphemerisBoolParams::GetGpsEphemerisBoolParams()
      : CommandBase(CmdName)
    {}

    GetGpsEphemerisBoolParams::GetGpsEphemerisBoolParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphemerisBoolParamsPtr GetGpsEphemerisBoolParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphemerisBoolParams>(paramName, dataSetName);
    }

    GetGpsEphemerisBoolParamsPtr GetGpsEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphemerisBoolParams>(ptr);
    }

    bool GetGpsEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphemerisBoolParams::documentation() const { return Documentation; }


    int GetGpsEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphemerisBoolParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphemerisBoolParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
