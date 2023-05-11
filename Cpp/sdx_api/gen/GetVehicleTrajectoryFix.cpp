
#include "gen/GetVehicleTrajectoryFix.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFix
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFix::CmdName = "GetVehicleTrajectoryFix";
    const char* const GetVehicleTrajectoryFix::Documentation = "Get vehicle static position and orientation";

    REGISTER_COMMAND_FACTORY(GetVehicleTrajectoryFix);


    GetVehicleTrajectoryFix::GetVehicleTrajectoryFix()
      : CommandBase(CmdName)
    {

    }

    GetVehicleTrajectoryFixPtr GetVehicleTrajectoryFix::create()
    {
      return std::make_shared<GetVehicleTrajectoryFix>();
    }

    GetVehicleTrajectoryFixPtr GetVehicleTrajectoryFix::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFix>(ptr);
    }

    bool GetVehicleTrajectoryFix::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryFix::documentation() const { return Documentation; }


    int GetVehicleTrajectoryFix::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
