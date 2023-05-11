
#include "gen/SetGpsSignalHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSignalHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSignalHealthForSV::CmdName = "SetGpsSignalHealthForSV";
    const char* const SetGpsSignalHealthForSV::Documentation = "Set GPS signal health";

    REGISTER_COMMAND_FACTORY(SetGpsSignalHealthForSV);


    SetGpsSignalHealthForSV::SetGpsSignalHealthForSV()
      : CommandBase(CmdName)
    {}

    SetGpsSignalHealthForSV::SetGpsSignalHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsSignalHealthForSVPtr SetGpsSignalHealthForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsSignalHealthForSV>(svId, health, dataSetName);
    }

    SetGpsSignalHealthForSVPtr SetGpsSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSignalHealthForSV>(ptr);
    }

    bool SetGpsSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsSignalHealthForSV::documentation() const { return Documentation; }


    int SetGpsSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsSignalHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetGpsSignalHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsSignalHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsSignalHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
