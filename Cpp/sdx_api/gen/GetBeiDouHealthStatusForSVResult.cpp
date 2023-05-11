
#include "gen/GetBeiDouHealthStatusForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthStatusForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthStatusForSVResult::CmdName = "GetBeiDouHealthStatusForSVResult";
    const char* const GetBeiDouHealthStatusForSVResult::Documentation = "Result of GetBeiDouHealthStatusForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetBeiDouHealthStatusForSVResult);


    GetBeiDouHealthStatusForSVResult::GetBeiDouHealthStatusForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouHealthStatusForSVResult::GetBeiDouHealthStatusForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthStatusForSVResult::GetBeiDouHealthStatusForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouHealthStatusForSVResultPtr GetBeiDouHealthStatusForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthStatusForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouHealthStatusForSVResultPtr GetBeiDouHealthStatusForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthStatusForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouHealthStatusForSVResultPtr GetBeiDouHealthStatusForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthStatusForSVResult>(ptr);
    }

    bool GetBeiDouHealthStatusForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthStatusForSVResult::documentation() const { return Documentation; }


    int GetBeiDouHealthStatusForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthStatusForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouHealthStatusForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouHealthStatusForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouHealthStatusForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthStatusForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
