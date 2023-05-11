
#include "gen/GetNavICNavAlertFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICNavAlertFlagForSV::CmdName = "GetNavICNavAlertFlagForSV";
    const char* const GetNavICNavAlertFlagForSV::Documentation = "Get NavIC NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetNavICNavAlertFlagForSV);


    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    GetNavICNavAlertFlagForSV::GetNavICNavAlertFlagForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICNavAlertFlagForSV>(svId, dataSetName);
    }

    GetNavICNavAlertFlagForSVPtr GetNavICNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICNavAlertFlagForSV>(ptr);
    }

    bool GetNavICNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICNavAlertFlagForSV::documentation() const { return Documentation; }


    int GetNavICNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
