
#include "gen/GetGalileoDataHealthForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoDataHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoDataHealthForSVResult::CmdName = "GetGalileoDataHealthForSVResult";
    const char* const GetGalileoDataHealthForSVResult::Documentation = "Result of GetGalileoDataHealthForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGalileoDataHealthForSVResult);


    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult(int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGalileoDataHealthForSVResultPtr GetGalileoDataHealthForSVResult::create(int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoDataHealthForSVResult>(svId, component, health, dataSetName);
    }

    GetGalileoDataHealthForSVResultPtr GetGalileoDataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoDataHealthForSVResult>(relatedCommand, svId, component, health, dataSetName);
    }

    GetGalileoDataHealthForSVResultPtr GetGalileoDataHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoDataHealthForSVResult>(ptr);
    }

    bool GetGalileoDataHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoDataHealthForSVResult::documentation() const { return Documentation; }


    int GetGalileoDataHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoDataHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoDataHealthForSVResult::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoDataHealthForSVResult::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoDataHealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGalileoDataHealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoDataHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoDataHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
