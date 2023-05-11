
#include "gen/EnableSimulationStopAtTrajectoryEnd.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSimulationStopAtTrajectoryEnd
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSimulationStopAtTrajectoryEnd::CmdName = "EnableSimulationStopAtTrajectoryEnd";
    const char* const EnableSimulationStopAtTrajectoryEnd::Documentation = "Set simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes";

    REGISTER_COMMAND_FACTORY(EnableSimulationStopAtTrajectoryEnd);


    EnableSimulationStopAtTrajectoryEnd::EnableSimulationStopAtTrajectoryEnd()
      : CommandBase(CmdName)
    {}

    EnableSimulationStopAtTrajectoryEnd::EnableSimulationStopAtTrajectoryEnd(bool enabled)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
    }

    EnableSimulationStopAtTrajectoryEndPtr EnableSimulationStopAtTrajectoryEnd::create(bool enabled)
    {
      return std::make_shared<EnableSimulationStopAtTrajectoryEnd>(enabled);
    }

    EnableSimulationStopAtTrajectoryEndPtr EnableSimulationStopAtTrajectoryEnd::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSimulationStopAtTrajectoryEnd>(ptr);
    }

    bool EnableSimulationStopAtTrajectoryEnd::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableSimulationStopAtTrajectoryEnd::documentation() const { return Documentation; }


    int EnableSimulationStopAtTrajectoryEnd::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableSimulationStopAtTrajectoryEnd::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSimulationStopAtTrajectoryEnd::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
