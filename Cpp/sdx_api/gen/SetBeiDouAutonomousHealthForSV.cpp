
#include "SetBeiDouAutonomousHealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouAutonomousHealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouAutonomousHealthForSV::CmdName = "SetBeiDouAutonomousHealthForSV";
    const char* const SetBeiDouAutonomousHealthForSV::Documentation = "Set BeiDou satellite autonomous health\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      bool            Status, false = Good, true = Not Good\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouAutonomousHealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouAutonomousHealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouAutonomousHealthForSV);


    SetBeiDouAutonomousHealthForSV::SetBeiDouAutonomousHealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouAutonomousHealthForSV::SetBeiDouAutonomousHealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouAutonomousHealthForSVPtr SetBeiDouAutonomousHealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouAutonomousHealthForSV>(svId, health, dataSetName);
    }

    SetBeiDouAutonomousHealthForSVPtr SetBeiDouAutonomousHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouAutonomousHealthForSV>(ptr);
    }

    bool SetBeiDouAutonomousHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouAutonomousHealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouAutonomousHealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetBeiDouAutonomousHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouAutonomousHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouAutonomousHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouAutonomousHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetBeiDouAutonomousHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouAutonomousHealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouAutonomousHealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
