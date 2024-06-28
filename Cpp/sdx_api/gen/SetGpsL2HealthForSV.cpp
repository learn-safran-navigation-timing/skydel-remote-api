
#include "SetGpsL2HealthForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsL2HealthForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsL2HealthForSV::CmdName = "SetGpsL2HealthForSV";
    const char* const SetGpsL2HealthForSV::Documentation = "Set GPS L2 health (used with CNAV and CNAV2)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L2 health, false = signal OK, true = signal bad or unavailable\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsL2HealthForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsL2HealthForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsL2HealthForSV);


    SetGpsL2HealthForSV::SetGpsL2HealthForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsL2HealthForSV::SetGpsL2HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetGpsL2HealthForSVPtr SetGpsL2HealthForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsL2HealthForSV>(svId, health, dataSetName);
    }

    SetGpsL2HealthForSVPtr SetGpsL2HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsL2HealthForSV>(ptr);
    }

    bool SetGpsL2HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsL2HealthForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsL2HealthForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetGpsL2HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsL2HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsL2HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsL2HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetGpsL2HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetGpsL2HealthForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsL2HealthForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
