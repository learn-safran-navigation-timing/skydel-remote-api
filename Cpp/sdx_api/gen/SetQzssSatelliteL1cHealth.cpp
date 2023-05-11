
#include "gen/SetQzssSatelliteL1cHealth.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL1cHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL1cHealth::CmdName = "SetQzssSatelliteL1cHealth";
    const char* const SetQzssSatelliteL1cHealth::Documentation = "Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.\n\nSet QZSS L1C health (Health of L1C signal)";

    REGISTER_COMMAND_FACTORY(SetQzssSatelliteL1cHealth);


    SetQzssSatelliteL1cHealth::SetQzssSatelliteL1cHealth()
      : CommandBase(CmdName)
    {}

    SetQzssSatelliteL1cHealth::SetQzssSatelliteL1cHealth(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL1cHealthPtr SetQzssSatelliteL1cHealth::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL1cHealth::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> SetQzssSatelliteL1cHealth::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL1cHealth::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
