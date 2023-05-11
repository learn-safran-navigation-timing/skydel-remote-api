
#include "gen/SetGpsNavAlertFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsNavAlertFlagForSV::CmdName = "SetGpsNavAlertFlagForSV";
    const char* const SetGpsNavAlertFlagForSV::Documentation = "Set GPS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsNavAlertFlagForSV);


    SetGpsNavAlertFlagForSV::SetGpsNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    SetGpsNavAlertFlagForSV::SetGpsNavAlertFlagForSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetGpsNavAlertFlagForSVPtr SetGpsNavAlertFlagForSV::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsNavAlertFlagForSV>(svId, alert, dataSetName);
    }

    SetGpsNavAlertFlagForSVPtr SetGpsNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsNavAlertFlagForSV>(ptr);
    }

    bool SetGpsNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsNavAlertFlagForSV::documentation() const { return Documentation; }


    int SetGpsNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsNavAlertFlagForSV::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void SetGpsNavAlertFlagForSV::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
