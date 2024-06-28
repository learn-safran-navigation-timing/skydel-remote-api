
#include "SetGpsCNavAlertFlagToSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsCNavAlertFlagToSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsCNavAlertFlagToSV::CmdName = "SetGpsCNavAlertFlagToSV";
    const char* const SetGpsCNavAlertFlagToSV::Documentation = "Set GPS CNAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            GPS CNAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsCNavAlertFlagToSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsCNavAlertFlagToSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsCNavAlertFlagToSV);


    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV(int svId, bool alert, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetGpsCNavAlertFlagToSVPtr SetGpsCNavAlertFlagToSV::create(int svId, bool alert, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsCNavAlertFlagToSV>(svId, alert, dataSetName);
    }

    SetGpsCNavAlertFlagToSVPtr SetGpsCNavAlertFlagToSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsCNavAlertFlagToSV>(ptr);
    }

    bool SetGpsCNavAlertFlagToSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsCNavAlertFlagToSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsCNavAlertFlagToSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


    int SetGpsCNavAlertFlagToSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsCNavAlertFlagToSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsCNavAlertFlagToSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsCNavAlertFlagToSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsCNavAlertFlagToSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsCNavAlertFlagToSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsCNavAlertFlagToSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
