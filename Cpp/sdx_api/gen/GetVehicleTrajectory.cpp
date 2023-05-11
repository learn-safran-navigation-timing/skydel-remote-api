
#include "gen/GetVehicleTrajectory.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectory
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectory::CmdName = "GetVehicleTrajectory";
    const char* const GetVehicleTrajectory::Documentation = "Get vehicle trajectory type";

    REGISTER_COMMAND_FACTORY(GetVehicleTrajectory);


    GetVehicleTrajectory::GetVehicleTrajectory()
      : CommandBase(CmdName)
    {

    }

    GetVehicleTrajectoryPtr GetVehicleTrajectory::create()
    {
      return std::make_shared<GetVehicleTrajectory>();
    }

    GetVehicleTrajectoryPtr GetVehicleTrajectory::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectory>(ptr);
    }

    bool GetVehicleTrajectory::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectory::documentation() const { return Documentation; }


    int GetVehicleTrajectory::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
