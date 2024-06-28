
#include "SetQzssNavAlertFlagForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssNavAlertFlagForSV::CmdName = "SetQzssNavAlertFlagForSV";
    const char* const SetQzssNavAlertFlagForSV::Documentation = "Set QZSS NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssNavAlertFlagForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssNavAlertFlagForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssNavAlertFlagForSV);


    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV(int svId, bool alert, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetQzssNavAlertFlagForSVPtr SetQzssNavAlertFlagForSV::create(int svId, bool alert, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssNavAlertFlagForSV>(svId, alert, dataSetName);
    }

    SetQzssNavAlertFlagForSVPtr SetQzssNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssNavAlertFlagForSV>(ptr);
    }

    bool SetQzssNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssNavAlertFlagForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssNavAlertFlagForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


    int SetQzssNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssNavAlertFlagForSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetQzssNavAlertFlagForSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssNavAlertFlagForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
