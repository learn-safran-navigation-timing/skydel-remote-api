
#include "gen/GetQzssL5HealthForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL5HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL5HealthForSVResult::CmdName = "GetQzssL5HealthForSVResult";
    const char* const GetQzssL5HealthForSVResult::Documentation = "Result of GetQzssL5HealthForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetQzssL5HealthForSVResult);


    GetQzssL5HealthForSVResult::GetQzssL5HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL5HealthForSVResult::GetQzssL5HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetQzssL5HealthForSVResult::GetQzssL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetQzssL5HealthForSVResultPtr GetQzssL5HealthForSVResult::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL5HealthForSVResult>(svId, health, dataSetName);
    }

    GetQzssL5HealthForSVResultPtr GetQzssL5HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssL5HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetQzssL5HealthForSVResultPtr GetQzssL5HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL5HealthForSVResult>(ptr);
    }

    bool GetQzssL5HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL5HealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL5HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL5HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL5HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetQzssL5HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL5HealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL5HealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
