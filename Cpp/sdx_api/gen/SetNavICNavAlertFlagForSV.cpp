
#include "SetNavICNavAlertFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICNavAlertFlagForSV::CmdName = "SetNavICNavAlertFlagForSV";
    const char* const SetNavICNavAlertFlagForSV::Documentation = "Set NavIC NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICNavAlertFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICNavAlertFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICNavAlertFlagForSV);


    SetNavICNavAlertFlagForSV::SetNavICNavAlertFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICNavAlertFlagForSV::SetNavICNavAlertFlagForSV(int svId, bool alert, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetNavICNavAlertFlagForSVPtr SetNavICNavAlertFlagForSV::create(int svId, bool alert, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICNavAlertFlagForSV>(svId, alert, dataSetName);
    }

    SetNavICNavAlertFlagForSVPtr SetNavICNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICNavAlertFlagForSV>(ptr);
    }

    bool SetNavICNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICNavAlertFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICNavAlertFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


    int SetNavICNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICNavAlertFlagForSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetNavICNavAlertFlagForSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICNavAlertFlagForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
