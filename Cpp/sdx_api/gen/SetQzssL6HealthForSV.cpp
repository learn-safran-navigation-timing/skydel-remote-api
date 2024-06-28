
#include "SetQzssL6HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL6HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL6HealthForSV::CmdName = "SetQzssL6HealthForSV";
    const char* const SetQzssL6HealthForSV::Documentation = "Set QZSS L6 health (Health of L6 signal).\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L6 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssL6HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssL6HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssL6HealthForSV);


    SetQzssL6HealthForSV::SetQzssL6HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssL6HealthForSV::SetQzssL6HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL6HealthForSVPtr SetQzssL6HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL6HealthForSV>(svId, health, dataSetName);
    }

    SetQzssL6HealthForSVPtr SetQzssL6HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL6HealthForSV>(ptr);
    }

    bool SetQzssL6HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL6HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssL6HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssL6HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL6HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL6HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL6HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL6HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssL6HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL6HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
