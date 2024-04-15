
#include "IsIonoOffsetEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIonoOffsetEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIonoOffsetEnabledResult::CmdName = "IsIonoOffsetEnabledResult";
    const char* const IsIonoOffsetEnabledResult::Documentation = "Result of IsIonoOffsetEnabled.\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- ---------------------------------------------\n"
      "IsEnabled bool True if offsets are applied on the ionosphere";
    const char* const IsIonoOffsetEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIonoOffsetEnabledResult);


    IsIonoOffsetEnabledResult::IsIonoOffsetEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsIonoOffsetEnabledResult::IsIonoOffsetEnabledResult(bool isEnabled)
      : CommandResult(CmdName, TargetId)
    {

      setIsEnabled(isEnabled);
    }

    IsIonoOffsetEnabledResult::IsIonoOffsetEnabledResult(CommandBasePtr relatedCommand, bool isEnabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsEnabled(isEnabled);
    }


    IsIonoOffsetEnabledResultPtr IsIonoOffsetEnabledResult::create(bool isEnabled)
    {
      return std::make_shared<IsIonoOffsetEnabledResult>(isEnabled);
    }

    IsIonoOffsetEnabledResultPtr IsIonoOffsetEnabledResult::create(CommandBasePtr relatedCommand, bool isEnabled)
    {
      return std::make_shared<IsIonoOffsetEnabledResult>(relatedCommand, isEnabled);
    }

    IsIonoOffsetEnabledResultPtr IsIonoOffsetEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIonoOffsetEnabledResult>(ptr);
    }

    bool IsIonoOffsetEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsIonoOffsetEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsIonoOffsetEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsEnabled"}; 
      return names; 
    }


    bool IsIonoOffsetEnabledResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsIonoOffsetEnabledResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
