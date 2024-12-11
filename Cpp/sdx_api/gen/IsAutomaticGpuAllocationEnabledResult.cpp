
#include "IsAutomaticGpuAllocationEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAutomaticGpuAllocationEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAutomaticGpuAllocationEnabledResult::CmdName = "IsAutomaticGpuAllocationEnabledResult";
    const char* const IsAutomaticGpuAllocationEnabledResult::Documentation = "Result of IsAutomaticGpuAllocationEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------------------------------------------------------------------------\n"
      "Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.";
    const char* const IsAutomaticGpuAllocationEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAutomaticGpuAllocationEnabledResult);


    IsAutomaticGpuAllocationEnabledResult::IsAutomaticGpuAllocationEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsAutomaticGpuAllocationEnabledResult::IsAutomaticGpuAllocationEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsAutomaticGpuAllocationEnabledResult::IsAutomaticGpuAllocationEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsAutomaticGpuAllocationEnabledResultPtr IsAutomaticGpuAllocationEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsAutomaticGpuAllocationEnabledResult>(enabled);
    }

    IsAutomaticGpuAllocationEnabledResultPtr IsAutomaticGpuAllocationEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsAutomaticGpuAllocationEnabledResult>(relatedCommand, enabled);
    }

    IsAutomaticGpuAllocationEnabledResultPtr IsAutomaticGpuAllocationEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAutomaticGpuAllocationEnabledResult>(ptr);
    }

    bool IsAutomaticGpuAllocationEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsAutomaticGpuAllocationEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsAutomaticGpuAllocationEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsAutomaticGpuAllocationEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsAutomaticGpuAllocationEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
