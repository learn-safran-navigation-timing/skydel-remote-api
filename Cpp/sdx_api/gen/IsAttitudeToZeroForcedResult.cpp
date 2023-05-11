
#include "gen/IsAttitudeToZeroForcedResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAttitudeToZeroForcedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAttitudeToZeroForcedResult::CmdName = "IsAttitudeToZeroForcedResult";
    const char* const IsAttitudeToZeroForcedResult::Documentation = "Result of IsAttitudeToZeroForced.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsAttitudeToZeroForcedResult);


    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult()
      : CommandResult(CmdName)
    {}

    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult(bool enabled)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
    }

    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsAttitudeToZeroForcedResultPtr IsAttitudeToZeroForcedResult::create(bool enabled)
    {
      return std::make_shared<IsAttitudeToZeroForcedResult>(enabled);
    }

    IsAttitudeToZeroForcedResultPtr IsAttitudeToZeroForcedResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsAttitudeToZeroForcedResult>(relatedCommand, enabled);
    }

    IsAttitudeToZeroForcedResultPtr IsAttitudeToZeroForcedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsAttitudeToZeroForcedResult>(ptr);
    }

    bool IsAttitudeToZeroForcedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsAttitudeToZeroForcedResult::documentation() const { return Documentation; }


    bool IsAttitudeToZeroForcedResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsAttitudeToZeroForcedResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
