
#include "Start.h"

#include "command_factory.h"
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
    const char* const Start::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Start);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Start);


    Start::Start()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& Start::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Start::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
