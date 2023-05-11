
#include "gen/GetGpsCNavAlertFlagToSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavAlertFlagToSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavAlertFlagToSV::CmdName = "GetGpsCNavAlertFlagToSV";
    const char* const GetGpsCNavAlertFlagToSV::Documentation = "Get GPS CNAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetGpsCNavAlertFlagToSV);


    GetGpsCNavAlertFlagToSV::GetGpsCNavAlertFlagToSV()
      : CommandBase(CmdName)
    {}

    GetGpsCNavAlertFlagToSV::GetGpsCNavAlertFlagToSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetGpsCNavAlertFlagToSVPtr GetGpsCNavAlertFlagToSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGpsCNavAlertFlagToSV>(svId, dataSetName);
    }

    GetGpsCNavAlertFlagToSVPtr GetGpsCNavAlertFlagToSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavAlertFlagToSV>(ptr);
    }

    bool GetGpsCNavAlertFlagToSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGpsCNavAlertFlagToSV::documentation() const { return Documentation; }


    int GetGpsCNavAlertFlagToSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsCNavAlertFlagToSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsCNavAlertFlagToSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGpsCNavAlertFlagToSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGpsCNavAlertFlagToSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
