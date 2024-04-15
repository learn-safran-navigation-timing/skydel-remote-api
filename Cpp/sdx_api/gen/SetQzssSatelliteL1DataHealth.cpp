
#include "SetQzssSatelliteL1DataHealth.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL1DataHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL1DataHealth::CmdName = "SetQzssSatelliteL1DataHealth";
    const char* const SetQzssSatelliteL1DataHealth::Documentation = "Please note the command SetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use SetQzssL1DataHealthForSV.\n"
      "\n"
      "Set QZSS L1 C/A nav data health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      int             Data health 0..7\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssSatelliteL1DataHealth::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssSatelliteL1DataHealth);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssSatelliteL1DataHealth);


    SetQzssSatelliteL1DataHealth::SetQzssSatelliteL1DataHealth()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssSatelliteL1DataHealth::SetQzssSatelliteL1DataHealth(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL1DataHealthPtr SetQzssSatelliteL1DataHealth::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssSatelliteL1DataHealth>(svId, health, dataSetName);
    }

    SetQzssSatelliteL1DataHealthPtr SetQzssSatelliteL1DataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatelliteL1DataHealth>(ptr);
    }

    bool SetQzssSatelliteL1DataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL1DataHealth::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssSatelliteL1DataHealth::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssSatelliteL1DataHealth::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssSatelliteL1DataHealth::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatelliteL1DataHealth::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssSatelliteL1DataHealth::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetQzssSatelliteL1DataHealth::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssSatelliteL1DataHealth::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL1DataHealth::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
