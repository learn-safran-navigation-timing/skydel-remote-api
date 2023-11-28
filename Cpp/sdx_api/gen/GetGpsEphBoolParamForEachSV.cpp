
#include "gen/GetGpsEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForEachSV::CmdName = "GetGpsEphBoolParamForEachSV";
    const char* const GetGpsEphBoolParamForEachSV::Documentation = "Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet GPS ephemeris boolean parameter value for all satellites";

    const char* const GetGpsEphBoolParamForEachSV::Deprecated = "Please note the command GetGpsEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetGpsEphBoolParamForEachSV);


    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetGpsEphBoolParamForEachSV::GetGpsEphBoolParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForEachSV>(paramName, dataSetName);
    }

    GetGpsEphBoolParamForEachSVPtr GetGpsEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForEachSV>(ptr);
    }

    bool GetGpsEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForEachSV::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetGpsEphBoolParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetGpsEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGpsEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
