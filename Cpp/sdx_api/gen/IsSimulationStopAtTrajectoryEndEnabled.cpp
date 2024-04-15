
#include "IsSimulationStopAtTrajectoryEndEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSimulationStopAtTrajectoryEndEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSimulationStopAtTrajectoryEndEnabled::CmdName = "IsSimulationStopAtTrajectoryEndEnabled";
    const char* const IsSimulationStopAtTrajectoryEndEnabled::Documentation = "Get simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes";
    const char* const IsSimulationStopAtTrajectoryEndEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSimulationStopAtTrajectoryEndEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSimulationStopAtTrajectoryEndEnabled);


    IsSimulationStopAtTrajectoryEndEnabled::IsSimulationStopAtTrajectoryEndEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsSimulationStopAtTrajectoryEndEnabledPtr IsSimulationStopAtTrajectoryEndEnabled::create()
    {
      return std::make_shared<IsSimulationStopAtTrajectoryEndEnabled>();
    }

    IsSimulationStopAtTrajectoryEndEnabledPtr IsSimulationStopAtTrajectoryEndEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSimulationStopAtTrajectoryEndEnabled>(ptr);
    }

    bool IsSimulationStopAtTrajectoryEndEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsSimulationStopAtTrajectoryEndEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSimulationStopAtTrajectoryEndEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsSimulationStopAtTrajectoryEndEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
