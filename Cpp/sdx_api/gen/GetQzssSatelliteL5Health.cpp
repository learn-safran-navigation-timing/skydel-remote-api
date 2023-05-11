
#include "gen/GetQzssSatelliteL5Health.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssSatelliteL5Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssSatelliteL5Health::CmdName = "GetQzssSatelliteL5Health";
    const char* const GetQzssSatelliteL5Health::Documentation = "Please note the command GetQzssSatelliteL5Health is deprecated since 21.3. You may use GetQzssL5HealthForSV.\n\nGet QZSS L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(GetQzssSatelliteL5Health);


    GetQzssSatelliteL5Health::GetQzssSatelliteL5Health()
      : CommandBase(CmdName)
    {}

    GetQzssSatelliteL5Health::GetQzssSatelliteL5Health(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetQzssSatelliteL5HealthPtr GetQzssSatelliteL5Health::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssSatelliteL5Health>(svId, dataSetName);
    }

    GetQzssSatelliteL5HealthPtr GetQzssSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssSatelliteL5Health>(ptr);
    }

    bool GetQzssSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssSatelliteL5Health::documentation() const { return Documentation; }


    int GetQzssSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetQzssSatelliteL5Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssSatelliteL5Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssSatelliteL5Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssSatelliteL5Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
