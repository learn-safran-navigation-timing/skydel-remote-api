
#include "SimulationElapsedTimeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SimulationElapsedTimeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SimulationElapsedTimeResult::CmdName = "SimulationElapsedTimeResult";
    const char* const SimulationElapsedTimeResult::Documentation = "Result of GetSimulationElapsedTime.\n"
      "\n"
      "Name         Type Description\n"
      "------------ ---- -----------------------------------------------------------------------------\n"
      "Milliseconds int  Simulation elapsed time in milliseconds. Note: Resolution is limited to 10Hz.";
    const char* const SimulationElapsedTimeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(SimulationElapsedTimeResult);


    SimulationElapsedTimeResult::SimulationElapsedTimeResult()
      : CommandResult(CmdName, TargetId)
    {}

    SimulationElapsedTimeResult::SimulationElapsedTimeResult(int milliseconds)
      : CommandResult(CmdName, TargetId)
    {

      setMilliseconds(milliseconds);
    }

    SimulationElapsedTimeResult::SimulationElapsedTimeResult(CommandBasePtr relatedCommand, int milliseconds)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setMilliseconds(milliseconds);
    }


    SimulationElapsedTimeResultPtr SimulationElapsedTimeResult::create(int milliseconds)
    {
      return std::make_shared<SimulationElapsedTimeResult>(milliseconds);
    }

    SimulationElapsedTimeResultPtr SimulationElapsedTimeResult::create(CommandBasePtr relatedCommand, int milliseconds)
    {
      return std::make_shared<SimulationElapsedTimeResult>(relatedCommand, milliseconds);
    }

    SimulationElapsedTimeResultPtr SimulationElapsedTimeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SimulationElapsedTimeResult>(ptr);
    }

    bool SimulationElapsedTimeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Milliseconds"])
        ;

    }

    std::string SimulationElapsedTimeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& SimulationElapsedTimeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Milliseconds"}; 
      return names; 
    }


    int SimulationElapsedTimeResult::milliseconds() const
    {
      return parse_json<int>::parse(m_values["Milliseconds"]);
    }

    void SimulationElapsedTimeResult::setMilliseconds(int milliseconds)
    {
      m_values.AddMember("Milliseconds", parse_json<int>::format(milliseconds, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
