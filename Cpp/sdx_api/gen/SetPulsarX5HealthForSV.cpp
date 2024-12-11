
#include "SetPulsarX5HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPulsarX5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPulsarX5HealthForSV::CmdName = "SetPulsarX5HealthForSV";
    const char* const SetPulsarX5HealthForSV::Documentation = "Set PULSAR X5 health (Health of X5 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X5 health, false = Signal not operational, true = Signal operational\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetPulsarX5HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPulsarX5HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPulsarX5HealthForSV);


    SetPulsarX5HealthForSV::SetPulsarX5HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPulsarX5HealthForSV::SetPulsarX5HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetPulsarX5HealthForSVPtr SetPulsarX5HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPulsarX5HealthForSV>(svId, health, dataSetName);
    }

    SetPulsarX5HealthForSVPtr SetPulsarX5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPulsarX5HealthForSV>(ptr);
    }

    bool SetPulsarX5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPulsarX5HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPulsarX5HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetPulsarX5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetPulsarX5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPulsarX5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPulsarX5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetPulsarX5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetPulsarX5HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPulsarX5HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
