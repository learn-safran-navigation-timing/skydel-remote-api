
#include "gen/RemoveAllModulationTargets.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllModulationTargets
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllModulationTargets::CmdName = "RemoveAllModulationTargets";
    const char* const RemoveAllModulationTargets::Documentation = "Remove all modulation targets.";

    REGISTER_COMMAND_FACTORY(RemoveAllModulationTargets);


    RemoveAllModulationTargets::RemoveAllModulationTargets()
      : CommandBase(CmdName)
    {

    }

    RemoveAllModulationTargetsPtr RemoveAllModulationTargets::create()
    {
      return std::make_shared<RemoveAllModulationTargets>();
    }

    RemoveAllModulationTargetsPtr RemoveAllModulationTargets::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllModulationTargets>(ptr);
    }

    bool RemoveAllModulationTargets::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllModulationTargets::documentation() const { return Documentation; }


    int RemoveAllModulationTargets::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
