
#include "gen/GetVehicleTrajectoryOrbit.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetVehicleTrajectoryOrbit);


    GetVehicleTrajectoryOrbit::GetVehicleTrajectoryOrbit()
      : CommandBase(CmdName)
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


    int GetVehicleTrajectoryOrbit::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
