
#include "gen/GetBeiDouCNavHealthInfoForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSVResult::CmdName = "GetBeiDouCNavHealthInfoForSVResult";
    const char* const GetBeiDouCNavHealthInfoForSVResult::Documentation = "Result of GetBeiDouCNavHealthInfoForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetBeiDouCNavHealthInfoForSVResult);


    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResult::GetBeiDouCNavHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouCNavHealthInfoForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouCNavHealthInfoForSVResultPtr GetBeiDouCNavHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSVResult::documentation() const { return Documentation; }


    int GetBeiDouCNavHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNavHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouCNavHealthInfoForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouCNavHealthInfoForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
