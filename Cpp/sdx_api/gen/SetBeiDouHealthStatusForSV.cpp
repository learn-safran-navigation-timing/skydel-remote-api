
#include "SetBeiDouHealthStatusForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouHealthStatusForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouHealthStatusForSV::CmdName = "SetBeiDouHealthStatusForSV";
    const char* const SetBeiDouHealthStatusForSV::Documentation = "Set BeiDou satellite health status\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      int             Health Info, 2-bit integer : 0, 1, 2 or 3\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouHealthStatusForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouHealthStatusForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouHealthStatusForSV);


    SetBeiDouHealthStatusForSV::SetBeiDouHealthStatusForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouHealthStatusForSV::SetBeiDouHealthStatusForSV(int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouHealthStatusForSVPtr SetBeiDouHealthStatusForSV::create(int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouHealthStatusForSV>(svId, health, dataSetName);
    }

    SetBeiDouHealthStatusForSVPtr SetBeiDouHealthStatusForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouHealthStatusForSV>(ptr);
    }

    bool SetBeiDouHealthStatusForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouHealthStatusForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouHealthStatusForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetBeiDouHealthStatusForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouHealthStatusForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouHealthStatusForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouHealthStatusForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouHealthStatusForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouHealthStatusForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouHealthStatusForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
