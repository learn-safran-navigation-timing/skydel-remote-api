
#include "EnableAutomaticGpuAllocation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableAutomaticGpuAllocation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableAutomaticGpuAllocation::CmdName = "EnableAutomaticGpuAllocation";
    const char* const EnableAutomaticGpuAllocation::Documentation = "Enable (or disable) automatic GPU allocation to outputs.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------------------------------------------------------\n"
      "Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.";
    const char* const EnableAutomaticGpuAllocation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableAutomaticGpuAllocation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableAutomaticGpuAllocation);


    EnableAutomaticGpuAllocation::EnableAutomaticGpuAllocation()
      : CommandBase(CmdName, TargetId)
    {}

    EnableAutomaticGpuAllocation::EnableAutomaticGpuAllocation(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableAutomaticGpuAllocationPtr EnableAutomaticGpuAllocation::create(bool enabled)
    {
      return std::make_shared<EnableAutomaticGpuAllocation>(enabled);
    }

    EnableAutomaticGpuAllocationPtr EnableAutomaticGpuAllocation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableAutomaticGpuAllocation>(ptr);
    }

    bool EnableAutomaticGpuAllocation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableAutomaticGpuAllocation::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableAutomaticGpuAllocation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableAutomaticGpuAllocation::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool EnableAutomaticGpuAllocation::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableAutomaticGpuAllocation::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
