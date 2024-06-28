
#include "GetGalileoDataHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoDataHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoDataHealthForSVResult::CmdName = "GetGalileoDataHealthForSVResult";
    const char* const GetGalileoDataHealthForSVResult::Documentation = "Result of GetGalileoDataHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID number 1..36.\n"
      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
      "Health      bool            False means Navigation data valid; True means Working without guarantee\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGalileoDataHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoDataHealthForSVResult);


    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGalileoDataHealthForSVResult::GetGalileoDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGalileoDataHealthForSVResultPtr GetGalileoDataHealthForSVResult::create(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoDataHealthForSVResult>(svId, component, health, dataSetName);
    }

    GetGalileoDataHealthForSVResultPtr GetGalileoDataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoDataHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoDataHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetGalileoDataHealthForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoDataHealthForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
