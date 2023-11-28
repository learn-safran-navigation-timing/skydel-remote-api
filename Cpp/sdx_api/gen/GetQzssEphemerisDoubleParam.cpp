
#include "gen/GetQzssEphemerisDoubleParam.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisDoubleParam::CmdName = "GetQzssEphemerisDoubleParam";
    const char* const GetQzssEphemerisDoubleParam::Documentation = "Please note the command GetQzssEphemerisDoubleParam is deprecated since 21.3. You may use GetQzssEphDoubleParamForSV.\n\nPlease note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet various parameters in the QZSS ephemeris.";

    const char* const GetQzssEphemerisDoubleParam::Deprecated = "Please note the command GetQzssEphemerisDoubleParam is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetQzssEphemerisDoubleParam);


    GetQzssEphemerisDoubleParam::GetQzssEphemerisDoubleParam()
      : CommandBase(CmdName)
    {}

    GetQzssEphemerisDoubleParam::GetQzssEphemerisDoubleParam(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisDoubleParamPtr GetQzssEphemerisDoubleParam::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisDoubleParam>(svId, paramName, dataSetName);
    }

    GetQzssEphemerisDoubleParamPtr GetQzssEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisDoubleParam>(ptr);
    }

    bool GetQzssEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisDoubleParam::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetQzssEphemerisDoubleParam::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetQzssEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisDoubleParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
