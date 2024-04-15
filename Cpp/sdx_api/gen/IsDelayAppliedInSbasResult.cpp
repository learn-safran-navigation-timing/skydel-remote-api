
#include "IsDelayAppliedInSbasResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsDelayAppliedInSbasResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsDelayAppliedInSbasResult::CmdName = "IsDelayAppliedInSbasResult";
    const char* const IsDelayAppliedInSbasResult::Documentation = "Result of IsDelayAppliedInSbas.\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- --------------------------------------------\n"
      "IsEnabled bool True if offsets are applied in Sbas messages";
    const char* const IsDelayAppliedInSbasResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsDelayAppliedInSbasResult);


    IsDelayAppliedInSbasResult::IsDelayAppliedInSbasResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsDelayAppliedInSbasResult::IsDelayAppliedInSbasResult(bool isEnabled)
      : CommandResult(CmdName, TargetId)
    {

      setIsEnabled(isEnabled);
    }

    IsDelayAppliedInSbasResult::IsDelayAppliedInSbasResult(CommandBasePtr relatedCommand, bool isEnabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIsEnabled(isEnabled);
    }


    IsDelayAppliedInSbasResultPtr IsDelayAppliedInSbasResult::create(bool isEnabled)
    {
      return std::make_shared<IsDelayAppliedInSbasResult>(isEnabled);
    }

    IsDelayAppliedInSbasResultPtr IsDelayAppliedInSbasResult::create(CommandBasePtr relatedCommand, bool isEnabled)
    {
      return std::make_shared<IsDelayAppliedInSbasResult>(relatedCommand, isEnabled);
    }

    IsDelayAppliedInSbasResultPtr IsDelayAppliedInSbasResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsDelayAppliedInSbasResult>(ptr);
    }

    bool IsDelayAppliedInSbasResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["IsEnabled"])
        ;

    }

    std::string IsDelayAppliedInSbasResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsDelayAppliedInSbasResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"IsEnabled"}; 
      return names; 
    }


    bool IsDelayAppliedInSbasResult::isEnabled() const
    {
      return parse_json<bool>::parse(m_values["IsEnabled"]);
    }

    void IsDelayAppliedInSbasResult::setIsEnabled(bool isEnabled)
    {
      m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
