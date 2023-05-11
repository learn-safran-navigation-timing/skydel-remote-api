
#include "gen/GetQzssNavAlertFlagForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSVResult::CmdName = "GetQzssNavAlertFlagForSVResult";
    const char* const GetQzssNavAlertFlagForSVResult::Documentation = "Result of GetQzssNavAlertFlagForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetQzssNavAlertFlagForSVResult);


    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }


    GetQzssNavAlertFlagForSVResultPtr GetQzssNavAlertFlagForSVResult::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssNavAlertFlagForSVResult>(svId, alert, dataSetName);
    }

    GetQzssNavAlertFlagForSVResultPtr GetQzssNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssNavAlertFlagForSVResult>(relatedCommand, svId, alert, dataSetName);
    }

    GetQzssNavAlertFlagForSVResultPtr GetQzssNavAlertFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSVResult>(ptr);
    }

    bool GetQzssNavAlertFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssNavAlertFlagForSVResult::documentation() const { return Documentation; }


    int GetQzssNavAlertFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssNavAlertFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssNavAlertFlagForSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetQzssNavAlertFlagForSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssNavAlertFlagForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssNavAlertFlagForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
