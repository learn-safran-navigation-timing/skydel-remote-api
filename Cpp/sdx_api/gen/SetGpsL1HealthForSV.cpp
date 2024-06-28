
#include "SetGpsL1HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL1HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL1HealthForSV::CmdName = "SetGpsL1HealthForSV";
    const char* const SetGpsL1HealthForSV::Documentation = "Set GPS L1 health (used with CNAV and CNAV2)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32\n"
      "Health      bool            L1 health, false = signal OK, true = signal bad or unavailable\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsL1HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsL1HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsL1HealthForSV);


    SetGpsL1HealthForSV::SetGpsL1HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsL1HealthForSV::SetGpsL1HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsL1HealthForSVPtr SetGpsL1HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsL1HealthForSV>(svId, health, dataSetName);
    }

    SetGpsL1HealthForSVPtr SetGpsL1HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL1HealthForSV>(ptr);
    }

    bool SetGpsL1HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsL1HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsL1HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGpsL1HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL1HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL1HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL1HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL1HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsL1HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsL1HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
