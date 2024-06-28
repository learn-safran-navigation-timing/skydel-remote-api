
#include "SetNavICSatelliteL5Health.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICSatelliteL5Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICSatelliteL5Health::CmdName = "SetNavICSatelliteL5Health";
    const char* const SetNavICSatelliteL5Health::Documentation = "Please note the command SetNavICSatelliteL5Health is deprecated since 21.3. You may use SetNavICL5HealthForSV.\n"
      "\n"
      "Set NavIC L5 health (Health of L5 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L5 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICSatelliteL5Health::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICSatelliteL5Health);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICSatelliteL5Health);


    SetNavICSatelliteL5Health::SetNavICSatelliteL5Health()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICSatelliteL5Health::SetNavICSatelliteL5Health(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetNavICSatelliteL5HealthPtr SetNavICSatelliteL5Health::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICSatelliteL5Health>(svId, health, dataSetName);
    }

    SetNavICSatelliteL5HealthPtr SetNavICSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICSatelliteL5Health>(ptr);
    }

    bool SetNavICSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICSatelliteL5Health::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICSatelliteL5Health::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetNavICSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICSatelliteL5Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICSatelliteL5Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICSatelliteL5Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICSatelliteL5Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICSatelliteL5Health::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICSatelliteL5Health::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
