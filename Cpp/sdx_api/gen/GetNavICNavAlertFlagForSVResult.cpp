
#include "GetNavICNavAlertFlagForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICNavAlertFlagForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICNavAlertFlagForSVResult::CmdName = "GetNavICNavAlertFlagForSVResult";
    const char* const GetNavICNavAlertFlagForSVResult::Documentation = "Result of GetNavICNavAlertFlagForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICNavAlertFlagForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICNavAlertFlagForSVResult);


    GetNavICNavAlertFlagForSVResult::GetNavICNavAlertFlagForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNavICNavAlertFlagForSVResult::GetNavICNavAlertFlagForSVResult(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }

    GetNavICNavAlertFlagForSVResult::GetNavICNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setAlert(alert);
      setDataSetName(dataSetName);
    }


    GetNavICNavAlertFlagForSVResultPtr GetNavICNavAlertFlagForSVResult::create(int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICNavAlertFlagForSVResult>(svId, alert, dataSetName);
    }

    GetNavICNavAlertFlagForSVResultPtr GetNavICNavAlertFlagForSVResult::create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICNavAlertFlagForSVResult>(relatedCommand, svId, alert, dataSetName);
    }

    GetNavICNavAlertFlagForSVResultPtr GetNavICNavAlertFlagForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICNavAlertFlagForSVResult>(ptr);
    }

    bool GetNavICNavAlertFlagForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Alert"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICNavAlertFlagForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICNavAlertFlagForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
      return names; 
    }


    int GetNavICNavAlertFlagForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICNavAlertFlagForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetNavICNavAlertFlagForSVResult::alert() const
    {
      return parse_json<bool>::parse(m_values["Alert"]);
    }

    void GetNavICNavAlertFlagForSVResult::setAlert(bool alert)
    {
      m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICNavAlertFlagForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICNavAlertFlagForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
