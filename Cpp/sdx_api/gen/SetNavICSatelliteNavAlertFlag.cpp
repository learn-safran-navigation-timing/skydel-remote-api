
#include "SetNavICSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICSatelliteNavAlertFlag::CmdName = "SetNavICSatelliteNavAlertFlag";
    const char* const SetNavICSatelliteNavAlertFlag::Documentation = "Please note the command SetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use SetNavICNavAlertFlagForSV.\n"
      "\n"
      "Set NavIC NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICSatelliteNavAlertFlag::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICSatelliteNavAlertFlag);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICSatelliteNavAlertFlag);


    SetNavICSatelliteNavAlertFlag::SetNavICSatelliteNavAlertFlag()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICSatelliteNavAlertFlag::SetNavICSatelliteNavAlertFlag(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetNavICSatelliteNavAlertFlag::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


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
