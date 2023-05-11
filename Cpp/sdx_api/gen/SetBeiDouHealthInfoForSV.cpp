
#include "gen/SetBeiDouHealthInfoForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouHealthInfoForSV::CmdName = "SetBeiDouHealthInfoForSV";
    const char* const SetBeiDouHealthInfoForSV::Documentation = "Set BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(SetBeiDouHealthInfoForSV);


    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouHealthInfoForSV>(svId, health, dataSetName);
    }

    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouHealthInfoForSV>(ptr);
    }

    bool SetBeiDouHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouHealthInfoForSV::documentation() const { return Documentation; }


    int SetBeiDouHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouHealthInfoForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouHealthInfoForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
