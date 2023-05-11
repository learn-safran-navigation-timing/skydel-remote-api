
#include "gen/GetAllModulationTargets.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetAllModulationTargets);


    GetAllModulationTargets::GetAllModulationTargets()
      : CommandBase(CmdName)
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


    int GetAllModulationTargets::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
