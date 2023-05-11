
#include "gen/GetGpsL1HealthForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL1HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL1HealthForSVResult::CmdName = "GetGpsL1HealthForSVResult";
    const char* const GetGpsL1HealthForSVResult::Documentation = "Result of GetGpsL1HealthForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsL1HealthForSVResult);


    GetGpsL1HealthForSVResult::GetGpsL1HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsL1HealthForSVResult::GetGpsL1HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGpsL1HealthForSVResult::GetGpsL1HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGpsL1HealthForSVResultPtr GetGpsL1HealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1HealthForSVResult>(svId, health, dataSetName);
    }

    GetGpsL1HealthForSVResultPtr GetGpsL1HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsL1HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetGpsL1HealthForSVResultPtr GetGpsL1HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL1HealthForSVResult>(ptr);
    }

    bool GetGpsL1HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsL1HealthForSVResult::documentation() const { return Documentation; }


    int GetGpsL1HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL1HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsL1HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsL1HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsL1HealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsL1HealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
