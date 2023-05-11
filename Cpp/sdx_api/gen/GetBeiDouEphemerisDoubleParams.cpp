
#include "gen/GetBeiDouEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouEphemerisDoubleParams::CmdName = "GetBeiDouEphemerisDoubleParams";
    const char* const GetBeiDouEphemerisDoubleParams::Documentation = "Please note the command GetBeiDouEphemerisDoubleParams is deprecated since 21.3. You may use GetBeiDouEphDoubleParamForEachSV.\n\nGet BeiDou ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetBeiDouEphemerisDoubleParams);


    GetBeiDouEphemerisDoubleParams::GetBeiDouEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    GetBeiDouEphemerisDoubleParams::GetBeiDouEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetBeiDouEphemerisDoubleParamsPtr GetBeiDouEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetBeiDouEphemerisDoubleParamsPtr GetBeiDouEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouEphemerisDoubleParams>(ptr);
    }

    bool GetBeiDouEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouEphemerisDoubleParams::documentation() const { return Documentation; }


    int GetBeiDouEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetBeiDouEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetBeiDouEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
