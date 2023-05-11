
#include "gen/IsTrajectoryCompleted.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectoryCompleted
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectoryCompleted::CmdName = "IsTrajectoryCompleted";
    const char* const IsTrajectoryCompleted::Documentation = "Returns whether the vehicle trajectory was completed.\nFor fixed, circular and earth-orbiting spacecraft, this will always return false.\nFor track playback and vehicle simulation, this will return true once the vehicle will reach the last position in the track/route.\nThe value is unreliable for HIL trajectories.";

    REGISTER_COMMAND_FACTORY(IsTrajectoryCompleted);


    IsTrajectoryCompleted::IsTrajectoryCompleted()
      : CommandBase(CmdName)
    {

    }

    IsTrajectoryCompletedPtr IsTrajectoryCompleted::create()
    {
      return std::make_shared<IsTrajectoryCompleted>();
    }

    IsTrajectoryCompletedPtr IsTrajectoryCompleted::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTrajectoryCompleted>(ptr);
    }

    bool IsTrajectoryCompleted::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsTrajectoryCompleted::documentation() const { return Documentation; }


    int IsTrajectoryCompleted::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
