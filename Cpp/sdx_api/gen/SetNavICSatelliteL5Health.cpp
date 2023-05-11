
#include "gen/SetNavICSatelliteL5Health.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICSatelliteL5Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICSatelliteL5Health::CmdName = "SetNavICSatelliteL5Health";
    const char* const SetNavICSatelliteL5Health::Documentation = "Please note the command SetNavICSatelliteL5Health is deprecated since 21.3. You may use SetNavICL5HealthForSV.\n\nSet NavIC L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(SetNavICSatelliteL5Health);


    SetNavICSatelliteL5Health::SetNavICSatelliteL5Health()
      : CommandBase(CmdName)
    {}

    SetNavICSatelliteL5Health::SetNavICSatelliteL5Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetNavICSatelliteL5HealthPtr SetNavICSatelliteL5Health::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICSatelliteL5Health>(svId, health, dataSetName);
    }

    SetNavICSatelliteL5HealthPtr SetNavICSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICSatelliteL5Health>(ptr);
    }

    bool SetNavICSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICSatelliteL5Health::documentation() const { return Documentation; }


    int SetNavICSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICSatelliteL5Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICSatelliteL5Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICSatelliteL5Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICSatelliteL5Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICSatelliteL5Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICSatelliteL5Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
