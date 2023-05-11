
#include "gen/GetBeiDouHealthInfoForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthInfoForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthInfoForSVResult::CmdName = "GetBeiDouHealthInfoForSVResult";
    const char* const GetBeiDouHealthInfoForSVResult::Documentation = "Result of GetBeiDouHealthInfoForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetBeiDouHealthInfoForSVResult);


    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetBeiDouHealthInfoForSVResult::GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthInfoForSVResult>(svId, health, dataSetName);
    }

    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetBeiDouHealthInfoForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetBeiDouHealthInfoForSVResultPtr GetBeiDouHealthInfoForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSVResult>(ptr);
    }

    bool GetBeiDouHealthInfoForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetBeiDouHealthInfoForSVResult::documentation() const { return Documentation; }


    int GetBeiDouHealthInfoForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthInfoForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouHealthInfoForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetBeiDouHealthInfoForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetBeiDouHealthInfoForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetBeiDouHealthInfoForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
