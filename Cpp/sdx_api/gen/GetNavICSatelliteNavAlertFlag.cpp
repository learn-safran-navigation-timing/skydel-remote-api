
#include "gen/GetNavICSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICSatelliteNavAlertFlag::CmdName = "GetNavICSatelliteNavAlertFlag";
    const char* const GetNavICSatelliteNavAlertFlag::Documentation = "Please note the command GetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use GetNavICNavAlertFlagForSV.\n\nGet NavIC NAV Alert Flag";

    REGISTER_COMMAND_FACTORY(GetNavICSatelliteNavAlertFlag);


    GetNavICSatelliteNavAlertFlag::GetNavICSatelliteNavAlertFlag()
      : CommandBase(CmdName)
    {}

    GetNavICSatelliteNavAlertFlag::GetNavICSatelliteNavAlertFlag(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICSatelliteNavAlertFlagPtr GetNavICSatelliteNavAlertFlag::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICSatelliteNavAlertFlag>(svId, dataSetName);
    }

    GetNavICSatelliteNavAlertFlagPtr GetNavICSatelliteNavAlertFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICSatelliteNavAlertFlag>(ptr);
    }

    bool GetNavICSatelliteNavAlertFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICSatelliteNavAlertFlag::documentation() const { return Documentation; }


    int GetNavICSatelliteNavAlertFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICSatelliteNavAlertFlag::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICSatelliteNavAlertFlag::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICSatelliteNavAlertFlag::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICSatelliteNavAlertFlag::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
