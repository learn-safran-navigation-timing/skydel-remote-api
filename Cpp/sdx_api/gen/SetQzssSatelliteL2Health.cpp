
#include "SetQzssSatelliteL2Health.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL2Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL2Health::CmdName = "SetQzssSatelliteL2Health";
    const char* const SetQzssSatelliteL2Health::Documentation = "Please note the command SetQzssSatelliteL2Health is deprecated since 21.3. You may use SetQzssL2HealthForSV.\n"
      "\n"
      "Set QZSS L2 health (Health of L2C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L2 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssSatelliteL2Health::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssSatelliteL2Health);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssSatelliteL2Health);


    SetQzssSatelliteL2Health::SetQzssSatelliteL2Health()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssSatelliteL2Health::SetQzssSatelliteL2Health(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL2HealthPtr SetQzssSatelliteL2Health::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssSatelliteL2Health>(svId, health, dataSetName);
    }

    SetQzssSatelliteL2HealthPtr SetQzssSatelliteL2Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatelliteL2Health>(ptr);
    }

    bool SetQzssSatelliteL2Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL2Health::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssSatelliteL2Health::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssSatelliteL2Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssSatelliteL2Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatelliteL2Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssSatelliteL2Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssSatelliteL2Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssSatelliteL2Health::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL2Health::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
