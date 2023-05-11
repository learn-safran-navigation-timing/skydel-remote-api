
#include "gen/IsTrajectorySmoothingEnabledResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsTrajectorySmoothingEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsTrajectorySmoothingEnabledResult::CmdName = "IsTrajectorySmoothingEnabledResult";
    const char* const IsTrajectorySmoothingEnabledResult::Documentation = "Result of IsTrajectorySmoothingEnabled.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsTrajectorySmoothingEnabledResult);


    IsTrajectorySmoothingEnabledResult::IsTrajectorySmoothingEnabledResult()
      : CommandResult(CmdName)
    {}

    IsTrajectorySmoothingEnabledResult::IsTrajectorySmoothingEnabledResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsTrajectorySmoothingEnabledResult::IsTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsTrajectorySmoothingEnabledResultPtr IsTrajectorySmoothingEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsTrajectorySmoothingEnabledResult>(enabled);
    }

    IsTrajectorySmoothingEnabledResultPtr IsTrajectorySmoothingEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsTrajectorySmoothingEnabledResult>(relatedCommand, enabled);
    }

    IsTrajectorySmoothingEnabledResultPtr IsTrajectorySmoothingEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsTrajectorySmoothingEnabledResult>(ptr);
    }

    bool IsTrajectorySmoothingEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsTrajectorySmoothingEnabledResult::documentation() const { return Documentation; }


    bool IsTrajectorySmoothingEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsTrajectorySmoothingEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
