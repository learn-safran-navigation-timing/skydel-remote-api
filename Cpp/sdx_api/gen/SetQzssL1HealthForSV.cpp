
#include "SetQzssL1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1HealthForSV::CmdName = "SetQzssL1HealthForSV";
    const char* const SetQzssL1HealthForSV::Documentation = "Set QZSS L1 health (Health of L1C/A signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L1 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssL1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssL1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssL1HealthForSV);


    SetQzssL1HealthForSV::SetQzssL1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssL1HealthForSV::SetQzssL1HealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL1HealthForSVPtr SetQzssL1HealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL1HealthForSV>(svId, health, dataSetName);
    }

    SetQzssL1HealthForSVPtr SetQzssL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1HealthForSV>(ptr);
    }

    bool SetQzssL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssL1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssL1HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL1HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
