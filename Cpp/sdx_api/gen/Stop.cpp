
#include "gen/Stop.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Stop
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Stop::CmdName = "Stop";
    const char* const Stop::Documentation = "Stop the simulation.";

    REGISTER_COMMAND_FACTORY(Stop);


    Stop::Stop()
      : CommandBase(CmdName)
    {

    }

    StopPtr Stop::create()
    {
      return std::make_shared<Stop>();
    }

    StopPtr Stop::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Stop>(ptr);
    }

    bool Stop::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Stop::documentation() const { return Documentation; }


    int Stop::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
