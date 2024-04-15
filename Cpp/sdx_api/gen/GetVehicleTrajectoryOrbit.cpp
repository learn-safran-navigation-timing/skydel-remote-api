
#include "GetVehicleTrajectoryOrbit.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryOrbit
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryOrbit::CmdName = "GetVehicleTrajectoryOrbit";
    const char* const GetVehicleTrajectoryOrbit::Documentation = "Get earth-orbiting spacecraft trajectory.";
    const char* const GetVehicleTrajectoryOrbit::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectoryOrbit);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleTrajectoryOrbit);


    GetVehicleTrajectoryOrbit::GetVehicleTrajectoryOrbit()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTrajectoryOrbitPtr GetVehicleTrajectoryOrbit::create()
    {
      return std::make_shared<GetVehicleTrajectoryOrbit>();
    }

    GetVehicleTrajectoryOrbitPtr GetVehicleTrajectoryOrbit::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryOrbit>(ptr);
    }

    bool GetVehicleTrajectoryOrbit::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryOrbit::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleTrajectoryOrbit::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleTrajectoryOrbit::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
