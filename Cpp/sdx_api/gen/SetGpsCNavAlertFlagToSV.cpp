
#include "gen/SetGpsCNavAlertFlagToSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsCNavAlertFlagToSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsCNavAlertFlagToSV::CmdName = "SetGpsCNavAlertFlagToSV";
    const char* const SetGpsCNavAlertFlagToSV::Documentation = "Set GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetGpsCNavAlertFlagToSV);


    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV()
      : CommandBase(CmdName)
    {}

    SetGpsCNavAlertFlagToSV::SetGpsCNavAlertFlagToSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetGpsCNavAlertFlagToSVPtr SetGpsCNavAlertFlagToSV::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsCNavAlertFlagToSV::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> SetGpsCNavAlertFlagToSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsCNavAlertFlagToSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
