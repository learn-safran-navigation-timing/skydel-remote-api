
#include "SetQzssL2HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL2HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL2HealthForSV::CmdName = "SetQzssL2HealthForSV";
    const char* const SetQzssL2HealthForSV::Documentation = "Set QZSS L2 health (Health of L2C signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L2 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssL2HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssL2HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssL2HealthForSV);


    SetQzssL2HealthForSV::SetQzssL2HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssL2HealthForSV::SetQzssL2HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssL2HealthForSVPtr SetQzssL2HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssL2HealthForSV>(svId, health, dataSetName);
    }

    SetQzssL2HealthForSVPtr SetQzssL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL2HealthForSV>(ptr);
    }

    bool SetQzssL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssL2HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssL2HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL2HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL2HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssL2HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssL2HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
