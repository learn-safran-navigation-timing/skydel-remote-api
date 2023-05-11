
#include "gen/GetNavICSatelliteL5Health.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICSatelliteL5Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICSatelliteL5Health::CmdName = "GetNavICSatelliteL5Health";
    const char* const GetNavICSatelliteL5Health::Documentation = "Please note the command GetNavICSatelliteL5Health is deprecated since 21.3. You may use GetNavICL5HealthForSV.\n\nGet NavIC L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(GetNavICSatelliteL5Health);


    GetNavICSatelliteL5Health::GetNavICSatelliteL5Health()
      : CommandBase(CmdName)
    {}

    GetNavICSatelliteL5Health::GetNavICSatelliteL5Health(int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetNavICSatelliteL5HealthPtr GetNavICSatelliteL5Health::create(int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICSatelliteL5Health>(svId, dataSetName);
    }

    GetNavICSatelliteL5HealthPtr GetNavICSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICSatelliteL5Health>(ptr);
    }

    bool GetNavICSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICSatelliteL5Health::documentation() const { return Documentation; }


    int GetNavICSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICSatelliteL5Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICSatelliteL5Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICSatelliteL5Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICSatelliteL5Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
