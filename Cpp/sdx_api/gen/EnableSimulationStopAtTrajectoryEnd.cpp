
#include "EnableSimulationStopAtTrajectoryEnd.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSimulationStopAtTrajectoryEnd
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSimulationStopAtTrajectoryEnd::CmdName = "EnableSimulationStopAtTrajectoryEnd";
    const char* const EnableSimulationStopAtTrajectoryEnd::Documentation = "Set simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ------------------------------------------------------------------------\n"
      "Enabled bool If true, simulation will stop when the vehicle will reach trajectory end";
    const char* const EnableSimulationStopAtTrajectoryEnd::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableSimulationStopAtTrajectoryEnd);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableSimulationStopAtTrajectoryEnd);


    EnableSimulationStopAtTrajectoryEnd::EnableSimulationStopAtTrajectoryEnd()
      : CommandBase(CmdName, TargetId)
    {}

    EnableSimulationStopAtTrajectoryEnd::EnableSimulationStopAtTrajectoryEnd(bool enabled)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& EnableSimulationStopAtTrajectoryEnd::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
