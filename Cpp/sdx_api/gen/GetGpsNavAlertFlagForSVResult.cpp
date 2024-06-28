
#include "GetGpsNavAlertFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavAlertFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavAlertFlagForSVResult::CmdName = "GetGpsNavAlertFlagForSVResult";
    const char* const GetGpsNavAlertFlagForSVResult::Documentation = "Result of GetGpsNavAlertFlagForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            GPS NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsNavAlertFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsNavAlertFlagForSVResult);


    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult(int svId, bool alert, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetGpsNavAlertFlagForSVResult::GetGpsNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }


    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::create(int svId, bool alert, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsNavAlertFlagForSVResult>(svId, alert, dataSetName);
    }

    GetGpsNavAlertFlagForSVResultPtr GetGpsNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsNavAlertFlagForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGpsNavAlertFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetGpsNavAlertFlagForSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsNavAlertFlagForSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
