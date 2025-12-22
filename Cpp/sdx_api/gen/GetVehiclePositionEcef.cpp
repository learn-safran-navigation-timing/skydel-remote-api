
#include "GetVehiclePositionEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehiclePositionEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehiclePositionEcef::CmdName = "GetVehiclePositionEcef";
    const char* const GetVehiclePositionEcef::Documentation = "Get Gets the vehicle's current ECEF position, or its initial position if the simulation is not running.\n"
      "\n"
      "Note: This command does not work with HIL trajectories in IDLE mode.";
    const char* const GetVehiclePositionEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehiclePositionEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehiclePositionEcef);


    GetVehiclePositionEcef::GetVehiclePositionEcef()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehiclePositionEcefPtr GetVehiclePositionEcef::create()
    {
      return std::make_shared<GetVehiclePositionEcef>();
    }

    GetVehiclePositionEcefPtr GetVehiclePositionEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehiclePositionEcef>(ptr);
    }

    bool GetVehiclePositionEcef::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehiclePositionEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehiclePositionEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehiclePositionEcef::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
