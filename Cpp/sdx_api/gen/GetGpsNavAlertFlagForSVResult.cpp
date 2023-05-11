
#include "gen/GetGpsNavAlertFlagForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavAlertFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavAlertFlagForSVResult::CmdName = "GetGpsNavAlertFlagForSVResult";
    const char* const GetGpsNavAlertFlagForSVResult::Documentation = "Result of GetGpsNavAlertFlagForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsNavAlertFlagForSVResult);


    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }


    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsNavAlertFlagForSVResult>(svId, alert, dataSetName);
    }

    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsNavAlertFlagForSVResult>(relatedCommand, svId, alert, dataSetName);
    }

    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavAlertFlagForSVResult>(ptr);
    }

    bool GetGpsNavAlertFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsNavAlertFlagForSVResult::documentation() const { return Documentation; }


    int GetGpsNavAlertFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsNavAlertFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsNavAlertFlagForSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetGpsNavAlertFlagForSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsNavAlertFlagForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsNavAlertFlagForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
