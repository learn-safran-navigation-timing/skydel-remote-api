
#include "gen/SetQzssL1DataHealthForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1DataHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1DataHealthForSV::CmdName = "SetQzssL1DataHealthForSV";
    const char* const SetQzssL1DataHealthForSV::Documentation = "Set QZSS L1 C/A nav data health";

    REGISTER_COMMAND_FACTORY(SetQzssL1DataHealthForSV);


    SetQzssL1DataHealthForSV::SetQzssL1DataHealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL1DataHealthForSV::SetQzssL1DataHealthForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL1DataHealthForSVPtr SetQzssL1DataHealthForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL1DataHealthForSV>(svId, health, dataSetName);
    }

    SetQzssL1DataHealthForSVPtr SetQzssL1DataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1DataHealthForSV>(ptr);
    }

    bool SetQzssL1DataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL1DataHealthForSV::documentation() const { return Documentation; }


    int SetQzssL1DataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1DataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1DataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssL1DataHealthForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetQzssL1DataHealthForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssL1DataHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL1DataHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
