
#include "gen/IsIntTxAttitudeToZeroForcedResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxAttitudeToZeroForcedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxAttitudeToZeroForcedResult::CmdName = "IsIntTxAttitudeToZeroForcedResult";
    const char* const IsIntTxAttitudeToZeroForcedResult::Documentation = "Result of IsIntTxAttitudeToZeroForced.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsIntTxAttitudeToZeroForcedResult);


    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult()
      : CommandResult(CmdName)
    {}

    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult(bool enabled, const std::string& id)
      : CommandResult(CmdName)
    {

      setEnabled(enabled);
      setId(id);
    }

    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
      setId(id);
    }


    IsIntTxAttitudeToZeroForcedResultPtr IsIntTxAttitudeToZeroForcedResult::create(bool enabled, const std::string& id)
    {
      return std::make_shared<IsIntTxAttitudeToZeroForcedResult>(enabled, id);
    }

    IsIntTxAttitudeToZeroForcedResultPtr IsIntTxAttitudeToZeroForcedResult::create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
    {
      return std::make_shared<IsIntTxAttitudeToZeroForcedResult>(relatedCommand, enabled, id);
    }

    IsIntTxAttitudeToZeroForcedResultPtr IsIntTxAttitudeToZeroForcedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxAttitudeToZeroForcedResult>(ptr);
    }

    bool IsIntTxAttitudeToZeroForcedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxAttitudeToZeroForcedResult::documentation() const { return Documentation; }


    bool IsIntTxAttitudeToZeroForcedResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsIntTxAttitudeToZeroForcedResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsIntTxAttitudeToZeroForcedResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxAttitudeToZeroForcedResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
