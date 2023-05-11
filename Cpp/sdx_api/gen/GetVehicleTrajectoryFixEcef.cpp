
#include "gen/GetVehicleTrajectoryFixEcef.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryFixEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryFixEcef::CmdName = "GetVehicleTrajectoryFixEcef";
    const char* const GetVehicleTrajectoryFixEcef::Documentation = "Get vehicle static position and orientation";

    REGISTER_COMMAND_FACTORY(GetVehicleTrajectoryFixEcef);


    GetVehicleTrajectoryFixEcef::GetVehicleTrajectoryFixEcef()
      : CommandBase(CmdName)
    {

    }

    GetVehicleTrajectoryFixEcefPtr GetVehicleTrajectoryFixEcef::create()
    {
      return std::make_shared<GetVehicleTrajectoryFixEcef>();
    }

    GetVehicleTrajectoryFixEcefPtr GetVehicleTrajectoryFixEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryFixEcef>(ptr);
    }

    bool GetVehicleTrajectoryFixEcef::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryFixEcef::documentation() const { return Documentation; }


    int GetVehicleTrajectoryFixEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
