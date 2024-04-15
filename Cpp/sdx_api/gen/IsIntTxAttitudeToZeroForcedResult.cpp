
#include "IsIntTxAttitudeToZeroForcedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxAttitudeToZeroForcedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxAttitudeToZeroForcedResult::CmdName = "IsIntTxAttitudeToZeroForcedResult";
    const char* const IsIntTxAttitudeToZeroForcedResult::Documentation = "Result of IsIntTxAttitudeToZeroForced.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ ------------------------------------------------------------\n"
      "Enabled bool   If true, interference vehicle won't rotate during simulation\n"
      "Id      string Transmitter unique identifier.";
    const char* const IsIntTxAttitudeToZeroForcedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsIntTxAttitudeToZeroForcedResult);


    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult(bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    IsIntTxAttitudeToZeroForcedResult::IsIntTxAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& IsIntTxAttitudeToZeroForcedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


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
