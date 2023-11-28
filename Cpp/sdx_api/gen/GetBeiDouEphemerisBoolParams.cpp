
#include "gen/GetBeiDouEphemerisBoolParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisBoolParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisBoolParams::CmdName = "GetBeiDouEphemerisBoolParams";
    const char* const GetBeiDouEphemerisBoolParams::Documentation = "Please note the command GetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use GetBeiDouEphBoolParamForEachSV.\n\nPlease note the command GetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet BeiDou ephemeris boolean parameter value for all satellites";

    const char* const GetBeiDouEphemerisBoolParams::Deprecated = "Please note the command GetBeiDouEphemerisBoolParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphemerisBoolParams);


    GetBeiDouEphemerisBoolParams::GetBeiDouEphemerisBoolParams()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphemerisBoolParams::GetBeiDouEphemerisBoolParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphemerisBoolParamsPtr GetBeiDouEphemerisBoolParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphemerisBoolParams>(paramName, dataSetName);
    }

    GetBeiDouEphemerisBoolParamsPtr GetBeiDouEphemerisBoolParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisBoolParams>(ptr);
    }

    bool GetBeiDouEphemerisBoolParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphemerisBoolParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetBeiDouEphemerisBoolParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetBeiDouEphemerisBoolParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphemerisBoolParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisBoolParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphemerisBoolParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphemerisBoolParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
