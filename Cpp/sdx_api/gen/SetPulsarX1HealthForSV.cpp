
#include "SetPulsarX1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPulsarX1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPulsarX1HealthForSV::CmdName = "SetPulsarX1HealthForSV";
    const char* const SetPulsarX1HealthForSV::Documentation = "Set PULSAR X1 health (Health of X1 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X1 health, false = Signal not operational, true = Signal operational\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetPulsarX1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPulsarX1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPulsarX1HealthForSV);


    SetPulsarX1HealthForSV::SetPulsarX1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPulsarX1HealthForSV::SetPulsarX1HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetPulsarX1HealthForSVPtr SetPulsarX1HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPulsarX1HealthForSV>(svId, health, dataSetName);
    }

    SetPulsarX1HealthForSVPtr SetPulsarX1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPulsarX1HealthForSV>(ptr);
    }

    bool SetPulsarX1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPulsarX1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPulsarX1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetPulsarX1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetPulsarX1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPulsarX1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPulsarX1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetPulsarX1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetPulsarX1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPulsarX1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
