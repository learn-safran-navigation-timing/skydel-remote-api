
#include "IsAutomaticGpuAllocationEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAutomaticGpuAllocationEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAutomaticGpuAllocationEnabled::CmdName = "IsAutomaticGpuAllocationEnabled";
    const char* const IsAutomaticGpuAllocationEnabled::Documentation = "Indicates whether GPUs are automatically allocated to outputs.";
    const char* const IsAutomaticGpuAllocationEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsAutomaticGpuAllocationEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAutomaticGpuAllocationEnabled);


    IsAutomaticGpuAllocationEnabled::IsAutomaticGpuAllocationEnabled()
      : CommandBase(CmdName, TargetId)
    {

    }

    IsAutomaticGpuAllocationEnabledPtr IsAutomaticGpuAllocationEnabled::create()
    {
      return std::make_shared<IsAutomaticGpuAllocationEnabled>();
    }

    IsAutomaticGpuAllocationEnabledPtr IsAutomaticGpuAllocationEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAutomaticGpuAllocationEnabled>(ptr);
    }

    bool IsAutomaticGpuAllocationEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsAutomaticGpuAllocationEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsAutomaticGpuAllocationEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int IsAutomaticGpuAllocationEnabled::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }

  }
}
