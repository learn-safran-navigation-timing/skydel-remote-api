
#include "GetQzssSatelliteL2Health.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL2Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL2Health::CmdName = "GetQzssSatelliteL2Health";
    const char* const GetQzssSatelliteL2Health::Documentation = "Please note the command GetQzssSatelliteL2Health is deprecated since 21.3. You may use GetQzssL2HealthForSV.\n"
      "\n"
      "Get QZSS L2 health (Health of L2C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetQzssSatelliteL2Health::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssSatelliteL2Health);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssSatelliteL2Health);


    GetQzssSatelliteL2Health::GetQzssSatelliteL2Health()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssSatelliteL2Health::GetQzssSatelliteL2Health(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL2HealthPtr GetQzssSatelliteL2Health::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteL2Health>(svId, dataSetName);
    }

    GetQzssSatelliteL2HealthPtr GetQzssSatelliteL2Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteL2Health>(ptr);
    }

    bool GetQzssSatelliteL2Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL2Health::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssSatelliteL2Health::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetQzssSatelliteL2Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteL2Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteL2Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssSatelliteL2Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL2Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
