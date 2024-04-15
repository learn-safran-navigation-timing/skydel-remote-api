
#include "GetAllModulationTargets.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllModulationTargets
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllModulationTargets::CmdName = "GetAllModulationTargets";
    const char* const GetAllModulationTargets::Documentation = "Get all the modulation targets IDs";
    const char* const GetAllModulationTargets::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllModulationTargets);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllModulationTargets);


    GetAllModulationTargets::GetAllModulationTargets()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetAllModulationTargetsPtr GetAllModulationTargets::create()
    {
      return std::make_shared<GetAllModulationTargets>();
    }

    GetAllModulationTargetsPtr GetAllModulationTargets::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllModulationTargets>(ptr);
    }

    bool GetAllModulationTargets::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAllModulationTargets::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllModulationTargets::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAllModulationTargets::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
