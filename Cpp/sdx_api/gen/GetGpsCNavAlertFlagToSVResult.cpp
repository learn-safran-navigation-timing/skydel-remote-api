
#include "GetGpsCNavAlertFlagToSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavAlertFlagToSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavAlertFlagToSVResult::CmdName = "GetGpsCNavAlertFlagToSVResult";
    const char* const GetGpsCNavAlertFlagToSVResult::Documentation = "Result of GetGpsCNavAlertFlagToSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            GPS CNAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGpsCNavAlertFlagToSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGpsCNavAlertFlagToSVResult);


    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetGpsCNavAlertFlagToSVResult::GetGpsCNavAlertFlagToSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetGpsCNavAlertFlagToSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


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
