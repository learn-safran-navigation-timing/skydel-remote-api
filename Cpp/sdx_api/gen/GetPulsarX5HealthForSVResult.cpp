
#include "GetPulsarX5HealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX5HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX5HealthForSVResult::CmdName = "GetPulsarX5HealthForSVResult";
    const char* const GetPulsarX5HealthForSVResult::Documentation = "Result of GetPulsarX5HealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X5 health, false = Signal not operational, true = Signal operational\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX5HealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX5HealthForSVResult);


    GetPulsarX5HealthForSVResult::GetPulsarX5HealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPulsarX5HealthForSVResult::GetPulsarX5HealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetPulsarX5HealthForSVResult::GetPulsarX5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetPulsarX5HealthForSVResultPtr GetPulsarX5HealthForSVResult::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5HealthForSVResult>(svId, health, dataSetName);
    }

    GetPulsarX5HealthForSVResultPtr GetPulsarX5HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetPulsarX5HealthForSVResultPtr GetPulsarX5HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX5HealthForSVResult>(ptr);
    }

    bool GetPulsarX5HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX5HealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX5HealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX5HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX5HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPulsarX5HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetPulsarX5HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX5HealthForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX5HealthForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
