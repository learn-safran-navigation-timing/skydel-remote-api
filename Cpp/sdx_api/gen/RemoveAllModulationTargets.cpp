
#include "RemoveAllModulationTargets.h"

#include "command_factory.h"
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
    const char* const RemoveAllModulationTargets::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllModulationTargets);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllModulationTargets);


    RemoveAllModulationTargets::RemoveAllModulationTargets()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RemoveAllModulationTargets::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RemoveAllModulationTargets::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
