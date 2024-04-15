
#include "GetQzssSatelliteL1cHealth.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL1cHealth
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL1cHealth::CmdName = "GetQzssSatelliteL1cHealth";
    const char* const GetQzssSatelliteL1cHealth::Documentation = "Please note the command GetQzssSatelliteL1cHealth is deprecated since 21.3. You may use GetQzssL1cHealthForSV.\n"
      "\n"
      "Get QZSS L1C health (Health of L1C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssSatelliteL1cHealth::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssSatelliteL1cHealth);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssSatelliteL1cHealth);


    GetQzssSatelliteL1cHealth::GetQzssSatelliteL1cHealth()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssSatelliteL1cHealth::GetQzssSatelliteL1cHealth(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL1cHealthPtr GetQzssSatelliteL1cHealth::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteL1cHealth>(svId, dataSetName);
    }

    GetQzssSatelliteL1cHealthPtr GetQzssSatelliteL1cHealth::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteL1cHealth>(ptr);
    }

    bool GetQzssSatelliteL1cHealth::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL1cHealth::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssSatelliteL1cHealth::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssSatelliteL1cHealth::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteL1cHealth::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteL1cHealth::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssSatelliteL1cHealth::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL1cHealth::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
