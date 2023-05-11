
#include "gen/GetQzssSatelliteL1Health.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL1Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL1Health::CmdName = "GetQzssSatelliteL1Health";
    const char* const GetQzssSatelliteL1Health::Documentation = "Please note the command GetQzssSatelliteL1Health is deprecated since 21.3. You may use GetQzssL1HealthForSV.\n\nGet QZSS L1 health (Health of L1C/A signal)";

    REGISTER_COMMAND_FACTORY(GetQzssSatelliteL1Health);


    GetQzssSatelliteL1Health::GetQzssSatelliteL1Health()
      : CommandBase(CmdName)
    {}

    GetQzssSatelliteL1Health::GetQzssSatelliteL1Health(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL1HealthPtr GetQzssSatelliteL1Health::create(int svId, const Sdx::optional<std::string>& dataSetName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL1Health::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetQzssSatelliteL1Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL1Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
