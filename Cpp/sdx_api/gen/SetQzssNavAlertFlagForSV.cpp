
#include "gen/SetQzssNavAlertFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssNavAlertFlagForSV::CmdName = "SetQzssNavAlertFlagForSV";
    const char* const SetQzssNavAlertFlagForSV::Documentation = "Set QZSS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(SetQzssNavAlertFlagForSV);


    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    SetQzssNavAlertFlagForSV::SetQzssNavAlertFlagForSV(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    SetQzssNavAlertFlagForSVPtr SetQzssNavAlertFlagForSV::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssNavAlertFlagForSV::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> SetQzssNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
