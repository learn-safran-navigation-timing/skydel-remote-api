
#include "gen/SetQzssL5HealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL5HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL5HealthForSV::CmdName = "SetQzssL5HealthForSV";
    const char* const SetQzssL5HealthForSV::Documentation = "Set QZSS L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(SetQzssL5HealthForSV);


    SetQzssL5HealthForSV::SetQzssL5HealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL5HealthForSV::SetQzssL5HealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL5HealthForSVPtr SetQzssL5HealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL5HealthForSV>(svId, health, dataSetName);
    }

    SetQzssL5HealthForSVPtr SetQzssL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL5HealthForSV>(ptr);
    }

    bool SetQzssL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL5HealthForSV::documentation() const { return Documentation; }


    int SetQzssL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
