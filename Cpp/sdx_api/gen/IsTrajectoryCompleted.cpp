
#include "IsTrajectoryCompleted.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectoryCompleted
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectoryCompleted::CmdName = "IsTrajectoryCompleted";
    const char* const IsTrajectoryCompleted::Documentation = "Returns whether the vehicle trajectory was completed.\n"
      "For fixed, circular and earth-orbiting spacecraft, this will always return false.\n"
      "For track playback and vehicle simulation, this will return true once the vehicle will reach the last position in the track/route.\n"
      "The value is unreliable for HIL trajectories.";
    const char* const IsTrajectoryCompleted::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsTrajectoryCompleted);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsTrajectoryCompleted);


    IsTrajectoryCompleted::IsTrajectoryCompleted()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& IsTrajectoryCompleted::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsTrajectoryCompleted::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
