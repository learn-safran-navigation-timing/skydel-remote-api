
#include "IsGroundVehicleTerrainFollowingEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGroundVehicleTerrainFollowingEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGroundVehicleTerrainFollowingEnabledResult::CmdName = "IsGroundVehicleTerrainFollowingEnabledResult";
    const char* const IsGroundVehicleTerrainFollowingEnabledResult::Documentation = "Result of IsGroundVehicleTerrainFollowingEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -------------------------------------------------------------------------------------------------\n"
      "Enabled bool If true, the altitude of ground vehicles is automatically adjusted to follow the terrain surface.";
    const char* const IsGroundVehicleTerrainFollowingEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsGroundVehicleTerrainFollowingEnabledResult);


    IsGroundVehicleTerrainFollowingEnabledResult::IsGroundVehicleTerrainFollowingEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsGroundVehicleTerrainFollowingEnabledResult::IsGroundVehicleTerrainFollowingEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsGroundVehicleTerrainFollowingEnabledResult::IsGroundVehicleTerrainFollowingEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsGroundVehicleTerrainFollowingEnabledResultPtr IsGroundVehicleTerrainFollowingEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsGroundVehicleTerrainFollowingEnabledResult>(enabled);
    }

    IsGroundVehicleTerrainFollowingEnabledResultPtr IsGroundVehicleTerrainFollowingEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsGroundVehicleTerrainFollowingEnabledResult>(relatedCommand, enabled);
    }

    IsGroundVehicleTerrainFollowingEnabledResultPtr IsGroundVehicleTerrainFollowingEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGroundVehicleTerrainFollowingEnabledResult>(ptr);
    }

    bool IsGroundVehicleTerrainFollowingEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsGroundVehicleTerrainFollowingEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsGroundVehicleTerrainFollowingEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsGroundVehicleTerrainFollowingEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsGroundVehicleTerrainFollowingEnabledResult::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
