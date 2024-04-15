
#include "SetQzssSatelliteL5Health.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssSatelliteL5Health
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssSatelliteL5Health::CmdName = "SetQzssSatelliteL5Health";
    const char* const SetQzssSatelliteL5Health::Documentation = "Please note the command SetQzssSatelliteL5Health is deprecated since 21.3. You may use SetQzssL5HealthForSV.\n"
      "\n"
      "Set QZSS L5 health (Health of L5 signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
      "Health      bool            L5 health, false = signal OK, true = signal bad\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssSatelliteL5Health::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssSatelliteL5Health);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssSatelliteL5Health);


    SetQzssSatelliteL5Health::SetQzssSatelliteL5Health()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssSatelliteL5Health::SetQzssSatelliteL5Health(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetQzssSatelliteL5HealthPtr SetQzssSatelliteL5Health::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssSatelliteL5Health>(svId, health, dataSetName);
    }

    SetQzssSatelliteL5HealthPtr SetQzssSatelliteL5Health::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssSatelliteL5Health>(ptr);
    }

    bool SetQzssSatelliteL5Health::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssSatelliteL5Health::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssSatelliteL5Health::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetQzssSatelliteL5Health::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssSatelliteL5Health::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssSatelliteL5Health::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssSatelliteL5Health::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssSatelliteL5Health::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssSatelliteL5Health::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssSatelliteL5Health::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
