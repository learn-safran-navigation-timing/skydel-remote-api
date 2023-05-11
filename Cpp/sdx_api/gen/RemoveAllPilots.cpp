
#include "gen/RemoveAllPilots.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllPilots
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllPilots::CmdName = "RemoveAllPilots";
    const char* const RemoveAllPilots::Documentation = "Remove all pilots on all outputs";

    REGISTER_COMMAND_FACTORY(RemoveAllPilots);


    RemoveAllPilots::RemoveAllPilots()
      : CommandBase(CmdName)
    {

    }

    RemoveAllPilotsPtr RemoveAllPilots::create()
    {
      return std::make_shared<RemoveAllPilots>();
    }

    RemoveAllPilotsPtr RemoveAllPilots::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllPilots>(ptr);
    }

    bool RemoveAllPilots::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllPilots::documentation() const { return Documentation; }


    int RemoveAllPilots::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
