
#include "IsGroundVehicleTerrainFollowingEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGroundVehicleTerrainFollowingEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGroundVehicleTerrainFollowingEnabled::CmdName = "IsGroundVehicleTerrainFollowingEnabled";
    const char* const IsGroundVehicleTerrainFollowingEnabled::Documentation = "Tells whether ground vehicles follow the terrain surface.";
    const char* const IsGroundVehicleTerrainFollowingEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsGroundVehicleTerrainFollowingEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsGroundVehicleTerrainFollowingEnabled);


    IsGroundVehicleTerrainFollowingEnabled::IsGroundVehicleTerrainFollowingEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsGroundVehicleTerrainFollowingEnabledPtr IsGroundVehicleTerrainFollowingEnabled::create()
    {
      return std::make_shared<IsGroundVehicleTerrainFollowingEnabled>();
    }

    IsGroundVehicleTerrainFollowingEnabledPtr IsGroundVehicleTerrainFollowingEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGroundVehicleTerrainFollowingEnabled>(ptr);
    }

    bool IsGroundVehicleTerrainFollowingEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsGroundVehicleTerrainFollowingEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsGroundVehicleTerrainFollowingEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsGroundVehicleTerrainFollowingEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
