
#include "EnableGroundVehicleTerrainFollowing.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableGroundVehicleTerrainFollowing
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableGroundVehicleTerrainFollowing::CmdName = "EnableGroundVehicleTerrainFollowing";
    const char* const EnableGroundVehicleTerrainFollowing::Documentation = "Enable (or disable) terrain-following behavior for ground vehicles.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -------------------------------------------------------------------------------------------------\n"
      "Enabled bool If true, the altitude of ground vehicles is automatically adjusted to follow the terrain surface.";
    const char* const EnableGroundVehicleTerrainFollowing::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableGroundVehicleTerrainFollowing);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableGroundVehicleTerrainFollowing);


    EnableGroundVehicleTerrainFollowing::EnableGroundVehicleTerrainFollowing()
      : CommandBase(CmdName, TargetId)
    {}

    EnableGroundVehicleTerrainFollowing::EnableGroundVehicleTerrainFollowing(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableGroundVehicleTerrainFollowingPtr EnableGroundVehicleTerrainFollowing::create(bool enabled)
    {
      return std::make_shared<EnableGroundVehicleTerrainFollowing>(enabled);
    }

    EnableGroundVehicleTerrainFollowingPtr EnableGroundVehicleTerrainFollowing::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableGroundVehicleTerrainFollowing>(ptr);
    }

    bool EnableGroundVehicleTerrainFollowing::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableGroundVehicleTerrainFollowing::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableGroundVehicleTerrainFollowing::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableGroundVehicleTerrainFollowing::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableGroundVehicleTerrainFollowing::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableGroundVehicleTerrainFollowing::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
