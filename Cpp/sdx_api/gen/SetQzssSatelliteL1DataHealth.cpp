
#include "gen/SetQzssSatelliteL1DataHealth.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL1DataHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL1DataHealth::CmdName = "SetQzssSatelliteL1DataHealth";
    const char* const SetQzssSatelliteL1DataHealth::Documentation = "Please note the command SetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use SetQzssL1DataHealthForSV.\n\nSet QZSS L1 C/A nav data health";

    REGISTER_COMMAND_FACTORY(SetQzssSatelliteL1DataHealth);


    SetQzssSatelliteL1DataHealth::SetQzssSatelliteL1DataHealth()
      : CommandBase(CmdName)
    {}

    SetQzssSatelliteL1DataHealth::SetQzssSatelliteL1DataHealth(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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
