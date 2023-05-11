
#include "gen/GetGpsCNavAlertFlagToSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavAlertFlagToSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavAlertFlagToSVResult::CmdName = "GetGpsCNavAlertFlagToSVResult";
    const char* const GetGpsCNavAlertFlagToSVResult::Documentation = "Result of GetGpsCNavAlertFlagToSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsCNavAlertFlagToSVResult);


    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }


    GetGpsCNavAlertFlagToSVResultPtr GetGpsCNavAlertFlagToSVResult::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsCNavAlertFlagToSVResult>(svId, alert, dataSetName);
    }

    GetGpsCNavAlertFlagToSVResultPtr GetGpsCNavAlertFlagToSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsCNavAlertFlagToSVResult>(relatedCommand, svId, alert, dataSetName);
    }

    GetGpsCNavAlertFlagToSVResultPtr GetGpsCNavAlertFlagToSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavAlertFlagToSVResult>(ptr);
    }

    bool GetGpsCNavAlertFlagToSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsCNavAlertFlagToSVResult::documentation() const { return Documentation; }


    int GetGpsCNavAlertFlagToSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsCNavAlertFlagToSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsCNavAlertFlagToSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetGpsCNavAlertFlagToSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsCNavAlertFlagToSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsCNavAlertFlagToSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
