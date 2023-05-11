
#include "gen/GetQzssSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteNavAlertFlag::CmdName = "GetQzssSatelliteNavAlertFlag";
    const char* const GetQzssSatelliteNavAlertFlag::Documentation = "Please note the command GetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use GetQzssNavAlertFlagForSV.\n\nGet QZSS NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetQzssSatelliteNavAlertFlag);


    GetQzssSatelliteNavAlertFlag::GetQzssSatelliteNavAlertFlag()
      : CommandBase(CmdName)
    {}

    GetQzssSatelliteNavAlertFlag::GetQzssSatelliteNavAlertFlag(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteNavAlertFlagPtr GetQzssSatelliteNavAlertFlag::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteNavAlertFlag>(svId, dataSetName);
    }

    GetQzssSatelliteNavAlertFlagPtr GetQzssSatelliteNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteNavAlertFlag>(ptr);
    }

    bool GetQzssSatelliteNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteNavAlertFlag::documentation() const { return Documentation; }


    int GetQzssSatelliteNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteNavAlertFlag::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteNavAlertFlag::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssSatelliteNavAlertFlag::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteNavAlertFlag::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
