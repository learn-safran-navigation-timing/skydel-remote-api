
#include "gen/SetGpsDataHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsDataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsDataHealthForSV::CmdName = "SetGpsDataHealthForSV";
    const char* const SetGpsDataHealthForSV::Documentation = "Set GPS nav data health";

    REGISTER_COMMAND_FACTORY(SetGpsDataHealthForSV);


    SetGpsDataHealthForSV::SetGpsDataHealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsDataHealthForSV::SetGpsDataHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsDataHealthForSV>(svId, health, dataSetName);
    }

    SetGpsDataHealthForSVPtr SetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsDataHealthForSV>(ptr);
    }

    bool SetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsDataHealthForSV::documentation() const { return Documentation; }


    int SetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsDataHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsDataHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsDataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsDataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
