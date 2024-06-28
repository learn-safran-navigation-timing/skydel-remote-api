
#include "GetQzssSatelliteL1DataHealth.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL1DataHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL1DataHealth::CmdName = "GetQzssSatelliteL1DataHealth";
    const char* const GetQzssSatelliteL1DataHealth::Documentation = "Please note the command GetQzssSatelliteL1DataHealth is deprecated since 21.3. You may use GetQzssL1DataHealthForSV.\n"
      "\n"
      "Get QZSS L1 C/A nav data health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssSatelliteL1DataHealth::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssSatelliteL1DataHealth);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssSatelliteL1DataHealth);


    GetQzssSatelliteL1DataHealth::GetQzssSatelliteL1DataHealth()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssSatelliteL1DataHealth::GetQzssSatelliteL1DataHealth(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL1DataHealthPtr GetQzssSatelliteL1DataHealth::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteL1DataHealth>(svId, dataSetName);
    }

    GetQzssSatelliteL1DataHealthPtr GetQzssSatelliteL1DataHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteL1DataHealth>(ptr);
    }

    bool GetQzssSatelliteL1DataHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL1DataHealth::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssSatelliteL1DataHealth::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssSatelliteL1DataHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteL1DataHealth::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteL1DataHealth::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssSatelliteL1DataHealth::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL1DataHealth::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
