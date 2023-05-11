
#include "gen/GetGpsL2HealthForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL2HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL2HealthForSVResult::CmdName = "GetGpsL2HealthForSVResult";
    const char* const GetGpsL2HealthForSVResult::Documentation = "Result of GetGpsL2HealthForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsL2HealthForSVResult);


    GetGpsL2HealthForSVResult::GetGpsL2HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsL2HealthForSVResult::GetGpsL2HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGpsL2HealthForSVResult::GetGpsL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGpsL2HealthForSVResultPtr GetGpsL2HealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL2HealthForSVResult>(svId, health, dataSetName);
    }

    GetGpsL2HealthForSVResultPtr GetGpsL2HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL2HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetGpsL2HealthForSVResultPtr GetGpsL2HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL2HealthForSVResult>(ptr);
    }

    bool GetGpsL2HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL2HealthForSVResult::documentation() const { return Documentation; }


    int GetGpsL2HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL2HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsL2HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsL2HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL2HealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL2HealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
