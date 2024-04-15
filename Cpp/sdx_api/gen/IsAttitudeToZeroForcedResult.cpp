
#include "IsAttitudeToZeroForcedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsAttitudeToZeroForcedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsAttitudeToZeroForcedResult::CmdName = "IsAttitudeToZeroForcedResult";
    const char* const IsAttitudeToZeroForcedResult::Documentation = "Result of IsAttitudeToZeroForced.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------------------------------------\n"
      "Enabled bool If true, vehicle won't rotate during simulation";
    const char* const IsAttitudeToZeroForcedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsAttitudeToZeroForcedResult);


    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsAttitudeToZeroForcedResult::IsAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsAttitudeToZeroForcedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


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
