
#include "gen/SetNavICNavAlertFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICNavAlertFlagForSV::CmdName = "SetNavICNavAlertFlagForSV";
    const char* const SetNavICNavAlertFlagForSV::Documentation = "Set NavIC NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetNavICNavAlertFlagForSV);


    SetNavICNavAlertFlagForSV::SetNavICNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    SetNavICNavAlertFlagForSV::SetNavICNavAlertFlagForSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetNavICNavAlertFlagForSVPtr SetNavICNavAlertFlagForSV::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICNavAlertFlagForSV::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> SetNavICNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
