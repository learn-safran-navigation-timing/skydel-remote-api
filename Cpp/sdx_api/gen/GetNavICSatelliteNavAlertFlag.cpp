
#include "GetNavICSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICSatelliteNavAlertFlag::CmdName = "GetNavICSatelliteNavAlertFlag";
    const char* const GetNavICSatelliteNavAlertFlag::Documentation = "Please note the command GetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use GetNavICNavAlertFlagForSV.\n"
      "\n"
      "Get NavIC NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICSatelliteNavAlertFlag::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICSatelliteNavAlertFlag);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICSatelliteNavAlertFlag);


    GetNavICSatelliteNavAlertFlag::GetNavICSatelliteNavAlertFlag()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICSatelliteNavAlertFlag::GetNavICSatelliteNavAlertFlag(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICSatelliteNavAlertFlagPtr GetNavICSatelliteNavAlertFlag::create(int svId, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICSatelliteNavAlertFlag::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICSatelliteNavAlertFlag::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetNavICSatelliteNavAlertFlag::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICSatelliteNavAlertFlag::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
