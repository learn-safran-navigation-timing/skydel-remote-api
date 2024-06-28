
#include "GetQzssSatelliteL1Health.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL1Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL1Health::CmdName = "GetQzssSatelliteL1Health";
    const char* const GetQzssSatelliteL1Health::Documentation = "Please note the command GetQzssSatelliteL1Health is deprecated since 21.3. You may use GetQzssL1HealthForSV.\n"
      "\n"
      "Get QZSS L1 health (Health of L1C/A signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssSatelliteL1Health::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssSatelliteL1Health);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssSatelliteL1Health);


    GetQzssSatelliteL1Health::GetQzssSatelliteL1Health()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssSatelliteL1Health::GetQzssSatelliteL1Health(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL1HealthPtr GetQzssSatelliteL1Health::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteL1Health>(svId, dataSetName);
    }

    GetQzssSatelliteL1HealthPtr GetQzssSatelliteL1Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteL1Health>(ptr);
    }

    bool GetQzssSatelliteL1Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL1Health::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssSatelliteL1Health::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssSatelliteL1Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteL1Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteL1Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetQzssSatelliteL1Health::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL1Health::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
