
#include "gen/GetQzssL2HealthForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL2HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL2HealthForSVResult::CmdName = "GetQzssL2HealthForSVResult";
    const char* const GetQzssL2HealthForSVResult::Documentation = "Result of GetQzssL2HealthForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetQzssL2HealthForSVResult);


    GetQzssL2HealthForSVResult::GetQzssL2HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL2HealthForSVResult::GetQzssL2HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetQzssL2HealthForSVResult::GetQzssL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetQzssL2HealthForSVResultPtr GetQzssL2HealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL2HealthForSVResult>(svId, health, dataSetName);
    }

    GetQzssL2HealthForSVResultPtr GetQzssL2HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL2HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetQzssL2HealthForSVResultPtr GetQzssL2HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL2HealthForSVResult>(ptr);
    }

    bool GetQzssL2HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL2HealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL2HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL2HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL2HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL2HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL2HealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL2HealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
