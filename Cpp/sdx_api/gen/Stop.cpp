
#include "Stop.h"

#include "command_factory.h"
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
    const char* const Stop::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Stop);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Stop);


    Stop::Stop()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& Stop::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Stop::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
