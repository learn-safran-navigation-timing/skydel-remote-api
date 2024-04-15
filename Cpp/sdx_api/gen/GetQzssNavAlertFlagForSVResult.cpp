
#include "GetQzssNavAlertFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSVResult::CmdName = "GetQzssNavAlertFlagForSVResult";
    const char* const GetQzssNavAlertFlagForSVResult::Documentation = "Result of GetQzssNavAlertFlagForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssNavAlertFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssNavAlertFlagForSVResult);


    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetQzssNavAlertFlagForSVResult::GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetQzssNavAlertFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


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
