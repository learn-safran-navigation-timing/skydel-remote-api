
#include "gen/GetQzssNavAlertFlagForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssNavAlertFlagForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssNavAlertFlagForSV::CmdName = "GetQzssNavAlertFlagForSV";
    const char* const GetQzssNavAlertFlagForSV::Documentation = "Get QZSS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetQzssNavAlertFlagForSV);


    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV()
      : CommandBase(CmdName)
    {}

    GetQzssNavAlertFlagForSV::GetQzssNavAlertFlagForSV(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssNavAlertFlagForSV>(svId, dataSetName);
    }

    GetQzssNavAlertFlagForSVPtr GetQzssNavAlertFlagForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSV>(ptr);
    }

    bool GetQzssNavAlertFlagForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssNavAlertFlagForSV::documentation() const { return Documentation; }


    int GetQzssNavAlertFlagForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssNavAlertFlagForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssNavAlertFlagForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssNavAlertFlagForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssNavAlertFlagForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
