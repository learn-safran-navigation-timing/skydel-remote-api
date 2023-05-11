
#include "gen/GetVehicleTrajectoryCircular.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleTrajectoryCircular
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleTrajectoryCircular::CmdName = "GetVehicleTrajectoryCircular";
    const char* const GetVehicleTrajectoryCircular::Documentation = "Get vehicle circular trajectory";

    REGISTER_COMMAND_FACTORY(GetVehicleTrajectoryCircular);


    GetVehicleTrajectoryCircular::GetVehicleTrajectoryCircular()
      : CommandBase(CmdName)
    {

    }

    GetVehicleTrajectoryCircularPtr GetVehicleTrajectoryCircular::create()
    {
      return std::make_shared<GetVehicleTrajectoryCircular>();
    }

    GetVehicleTrajectoryCircularPtr GetVehicleTrajectoryCircular::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleTrajectoryCircular>(ptr);
    }

    bool GetVehicleTrajectoryCircular::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleTrajectoryCircular::documentation() const { return Documentation; }


    int GetVehicleTrajectoryCircular::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
