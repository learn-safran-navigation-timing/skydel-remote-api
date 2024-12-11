
#include "GetPulsarX1HealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX1HealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX1HealthForSVResult::CmdName = "GetPulsarX1HealthForSVResult";
    const char* const GetPulsarX1HealthForSVResult::Documentation = "Result of GetPulsarX1HealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X1 health, false = Signal not operational, true = Signal operational\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX1HealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX1HealthForSVResult);


    GetPulsarX1HealthForSVResult::GetPulsarX1HealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPulsarX1HealthForSVResult::GetPulsarX1HealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetPulsarX1HealthForSVResult::GetPulsarX1HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetPulsarX1HealthForSVResultPtr GetPulsarX1HealthForSVResult::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1HealthForSVResult>(svId, health, dataSetName);
    }

    GetPulsarX1HealthForSVResultPtr GetPulsarX1HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetPulsarX1HealthForSVResultPtr GetPulsarX1HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX1HealthForSVResult>(ptr);
    }

    bool GetPulsarX1HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX1HealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX1HealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX1HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX1HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetPulsarX1HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetPulsarX1HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX1HealthForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX1HealthForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
