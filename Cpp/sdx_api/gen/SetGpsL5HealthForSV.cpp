
#include "gen/SetGpsL5HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL5HealthForSV::CmdName = "SetGpsL5HealthForSV";
    const char* const SetGpsL5HealthForSV::Documentation = "Set GPS L5 health (used with CNAV and CNAV2)";

    REGISTER_COMMAND_FACTORY(SetGpsL5HealthForSV);


    SetGpsL5HealthForSV::SetGpsL5HealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsL5HealthForSV::SetGpsL5HealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsL5HealthForSVPtr SetGpsL5HealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsL5HealthForSV>(svId, health, dataSetName);
    }

    SetGpsL5HealthForSVPtr SetGpsL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL5HealthForSV>(ptr);
    }

    bool SetGpsL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsL5HealthForSV::documentation() const { return Documentation; }


    int SetGpsL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
