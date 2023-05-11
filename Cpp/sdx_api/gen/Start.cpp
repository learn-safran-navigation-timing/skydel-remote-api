
#include "gen/Start.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Start
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Start::CmdName = "Start";
    const char* const Start::Documentation = "Start the simulation. Simulation may or may not start depending on the current state of the simulator.";

    REGISTER_COMMAND_FACTORY(Start);


    Start::Start()
      : CommandBase(CmdName)
    {

    }

    StartPtr Start::create()
    {
      return std::make_shared<Start>();
    }

    StartPtr Start::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Start>(ptr);
    }

    bool Start::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Start::documentation() const { return Documentation; }


    int Start::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
