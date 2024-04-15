
#include "Pause.h"

#include "command_factory.h"
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
    const char* const Pause::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Pause);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Pause);


    Pause::Pause()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& Pause::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Pause::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
