
#include "GetQzssSatelliteNavAlertFlag.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteNavAlertFlag
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteNavAlertFlag::CmdName = "GetQzssSatelliteNavAlertFlag";
    const char* const GetQzssSatelliteNavAlertFlag::Documentation = "Please note the command GetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use GetQzssNavAlertFlagForSV.\n"
      "\n"
      "Get QZSS NAV Alert Flag\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssSatelliteNavAlertFlag::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssSatelliteNavAlertFlag);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssSatelliteNavAlertFlag);


    GetQzssSatelliteNavAlertFlag::GetQzssSatelliteNavAlertFlag()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssSatelliteNavAlertFlag::GetQzssSatelliteNavAlertFlag(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteNavAlertFlagPtr GetQzssSatelliteNavAlertFlag::create(int svId, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteNavAlertFlag::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssSatelliteNavAlertFlag::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetQzssSatelliteNavAlertFlag::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteNavAlertFlag::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
