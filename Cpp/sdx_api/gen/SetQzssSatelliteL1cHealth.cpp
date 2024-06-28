
#include "SetQzssSatelliteL1cHealth.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL1cHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL1cHealth::CmdName = "SetQzssSatelliteL1cHealth";
    const char* const SetQzssSatelliteL1cHealth::Documentation = "Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.\n"
      "\n"
      "Set QZSS L1C health (Health of L1C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1C health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssSatelliteL1cHealth::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssSatelliteL1cHealth);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssSatelliteL1cHealth);


    SetQzssSatelliteL1cHealth::SetQzssSatelliteL1cHealth()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssSatelliteL1cHealth::SetQzssSatelliteL1cHealth(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL1cHealthPtr SetQzssSatelliteL1cHealth::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssSatelliteL1cHealth>(svId, health, dataSetName);
    }

    SetQzssSatelliteL1cHealthPtr SetQzssSatelliteL1cHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatelliteL1cHealth>(ptr);
    }

    bool SetQzssSatelliteL1cHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL1cHealth::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssSatelliteL1cHealth::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssSatelliteL1cHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssSatelliteL1cHealth::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatelliteL1cHealth::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssSatelliteL1cHealth::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssSatelliteL1cHealth::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssSatelliteL1cHealth::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL1cHealth::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
