
#include "gen/SetNavICSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICSatelliteNavAlertFlag::CmdName = "SetNavICSatelliteNavAlertFlag";
    const char* const SetNavICSatelliteNavAlertFlag::Documentation = "Please note the command SetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use SetNavICNavAlertFlagForSV.\n\nSet NavIC NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetNavICSatelliteNavAlertFlag);


    SetNavICSatelliteNavAlertFlag::SetNavICSatelliteNavAlertFlag()
      : CommandBase(CmdName)
    {}

    SetNavICSatelliteNavAlertFlag::SetNavICSatelliteNavAlertFlag(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetNavICSatelliteNavAlertFlagPtr SetNavICSatelliteNavAlertFlag::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICSatelliteNavAlertFlag>(svId, alert, dataSetName);
    }

    SetNavICSatelliteNavAlertFlagPtr SetNavICSatelliteNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICSatelliteNavAlertFlag>(ptr);
    }

    bool SetNavICSatelliteNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICSatelliteNavAlertFlag::documentation() const { return Documentation; }


    int SetNavICSatelliteNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICSatelliteNavAlertFlag::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICSatelliteNavAlertFlag::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICSatelliteNavAlertFlag::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetNavICSatelliteNavAlertFlag::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICSatelliteNavAlertFlag::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICSatelliteNavAlertFlag::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
