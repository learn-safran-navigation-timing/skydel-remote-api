
#include "gen/GetQzssEphemerisBoolParam.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphemerisBoolParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphemerisBoolParam::CmdName = "GetQzssEphemerisBoolParam";
    const char* const GetQzssEphemerisBoolParam::Documentation = "Please note the command GetQzssEphemerisBoolParam is deprecated since 21.3. You may use GetQzssEphBoolParamForSV.\n\nGet various boolean parameters in the QZSS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    REGISTER_COMMAND_FACTORY(GetQzssEphemerisBoolParam);


    GetQzssEphemerisBoolParam::GetQzssEphemerisBoolParam()
      : CommandBase(CmdName)
    {}

    GetQzssEphemerisBoolParam::GetQzssEphemerisBoolParam(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphemerisBoolParamPtr GetQzssEphemerisBoolParam::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphemerisBoolParam>(svId, paramName, dataSetName);
    }

    GetQzssEphemerisBoolParamPtr GetQzssEphemerisBoolParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphemerisBoolParam>(ptr);
    }

    bool GetQzssEphemerisBoolParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphemerisBoolParam::documentation() const { return Documentation; }


    int GetQzssEphemerisBoolParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssEphemerisBoolParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphemerisBoolParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphemerisBoolParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphemerisBoolParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphemerisBoolParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphemerisBoolParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
