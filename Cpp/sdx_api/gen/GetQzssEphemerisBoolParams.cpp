
#include "gen/GetQzssEphemerisBoolParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisBoolParams::CmdName = "GetQzssEphemerisBoolParams";
    const char* const GetQzssEphemerisBoolParams::Documentation = "Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.\n\nGet QZSS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetQzssEphemerisBoolParams);


    GetQzssEphemerisBoolParams::GetQzssEphemerisBoolParams()
      : CommandBase(CmdName)
    {}

    GetQzssEphemerisBoolParams::GetQzssEphemerisBoolParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisBoolParamsPtr GetQzssEphemerisBoolParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisBoolParams>(paramName, dataSetName);
    }

    GetQzssEphemerisBoolParamsPtr GetQzssEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisBoolParams>(ptr);
    }

    bool GetQzssEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisBoolParams::documentation() const { return Documentation; }


    int GetQzssEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphemerisBoolParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisBoolParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
