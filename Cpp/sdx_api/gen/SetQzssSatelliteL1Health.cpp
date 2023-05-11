
#include "gen/SetQzssSatelliteL1Health.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL1Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL1Health::CmdName = "SetQzssSatelliteL1Health";
    const char* const SetQzssSatelliteL1Health::Documentation = "Please note the command SetQzssSatelliteL1Health is deprecated since 21.3. You may use SetQzssL1HealthForSV.\n\nSet QZSS L1 health (Health of L1C/A signal)";

    REGISTER_COMMAND_FACTORY(SetQzssSatelliteL1Health);


    SetQzssSatelliteL1Health::SetQzssSatelliteL1Health()
      : CommandBase(CmdName)
    {}

    SetQzssSatelliteL1Health::SetQzssSatelliteL1Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL1HealthPtr SetQzssSatelliteL1Health::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssSatelliteL1Health>(svId, health, dataSetName);
    }

    SetQzssSatelliteL1HealthPtr SetQzssSatelliteL1Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatelliteL1Health>(ptr);
    }

    bool SetQzssSatelliteL1Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL1Health::documentation() const { return Documentation; }


    int SetQzssSatelliteL1Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssSatelliteL1Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatelliteL1Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssSatelliteL1Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssSatelliteL1Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssSatelliteL1Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL1Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
