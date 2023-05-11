
#include "gen/Pause.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Pause
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Pause::CmdName = "Pause";
    const char* const Pause::Documentation = "Pause vehicle motion during simulation.";

    REGISTER_COMMAND_FACTORY(Pause);


    Pause::Pause()
      : CommandBase(CmdName)
    {

    }

    PausePtr Pause::create()
    {
      return std::make_shared<Pause>();
    }

    PausePtr Pause::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Pause>(ptr);
    }

    bool Pause::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Pause::documentation() const { return Documentation; }


    int Pause::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
