
#include "gen/GetGpsEphBoolParamForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsEphBoolParamForSV::CmdName = "GetGpsEphBoolParamForSV";
    const char* const GetGpsEphBoolParamForSV::Documentation = "Get various boolean parameters in the GPS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    REGISTER_COMMAND_FACTORY(GetGpsEphBoolParamForSV);


    GetGpsEphBoolParamForSV::GetGpsEphBoolParamForSV()
      : CommandBase(CmdName)
    {}

    GetGpsEphBoolParamForSV::GetGpsEphBoolParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetGpsEphBoolParamForSVPtr GetGpsEphBoolParamForSV::create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsEphBoolParamForSV>(svId, paramName, dataSetName);
    }

    GetGpsEphBoolParamForSVPtr GetGpsEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsEphBoolParamForSV>(ptr);
    }

    bool GetGpsEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsEphBoolParamForSV::documentation() const { return Documentation; }


    int GetGpsEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGpsEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
