
#include "gen/SetBeiDouCNavHealthInfoForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouCNavHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouCNavHealthInfoForSV::CmdName = "SetBeiDouCNavHealthInfoForSV";
    const char* const SetBeiDouCNavHealthInfoForSV::Documentation = "Set BeiDou CNav satellite health info";

    REGISTER_COMMAND_FACTORY(SetBeiDouCNavHealthInfoForSV);


    SetBeiDouCNavHealthInfoForSV::SetBeiDouCNavHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouCNavHealthInfoForSV::SetBeiDouCNavHealthInfoForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouCNavHealthInfoForSVPtr SetBeiDouCNavHealthInfoForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouCNavHealthInfoForSV>(svId, health, dataSetName);
    }

    SetBeiDouCNavHealthInfoForSVPtr SetBeiDouCNavHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouCNavHealthInfoForSV>(ptr);
    }

    bool SetBeiDouCNavHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouCNavHealthInfoForSV::documentation() const { return Documentation; }


    int SetBeiDouCNavHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouCNavHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouCNavHealthInfoForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouCNavHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
