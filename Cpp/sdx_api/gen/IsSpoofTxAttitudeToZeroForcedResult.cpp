
#include "IsSpoofTxAttitudeToZeroForcedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxAttitudeToZeroForcedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxAttitudeToZeroForcedResult::CmdName = "IsSpoofTxAttitudeToZeroForcedResult";
    const char* const IsSpoofTxAttitudeToZeroForcedResult::Documentation = "Result of IsSpoofTxAttitudeToZeroForced.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------\n"
      "Enabled bool   If true, spoofer transmitter vehicle won't rotate during simulation\n"
      "Id      string Transmitter unique identifier.";
    const char* const IsSpoofTxAttitudeToZeroForcedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxAttitudeToZeroForcedResult);


    IsSpoofTxAttitudeToZeroForcedResult::IsSpoofTxAttitudeToZeroForcedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSpoofTxAttitudeToZeroForcedResult::IsSpoofTxAttitudeToZeroForcedResult(bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    IsSpoofTxAttitudeToZeroForcedResult::IsSpoofTxAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setId(id);
    }


    IsSpoofTxAttitudeToZeroForcedResultPtr IsSpoofTxAttitudeToZeroForcedResult::create(bool enabled, const std::string& id)
    {
      return std::make_shared<IsSpoofTxAttitudeToZeroForcedResult>(enabled, id);
    }

    IsSpoofTxAttitudeToZeroForcedResultPtr IsSpoofTxAttitudeToZeroForcedResult::create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
    {
      return std::make_shared<IsSpoofTxAttitudeToZeroForcedResult>(relatedCommand, enabled, id);
    }

    IsSpoofTxAttitudeToZeroForcedResultPtr IsSpoofTxAttitudeToZeroForcedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxAttitudeToZeroForcedResult>(ptr);
    }

    bool IsSpoofTxAttitudeToZeroForcedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxAttitudeToZeroForcedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxAttitudeToZeroForcedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    bool IsSpoofTxAttitudeToZeroForcedResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsSpoofTxAttitudeToZeroForcedResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string IsSpoofTxAttitudeToZeroForcedResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxAttitudeToZeroForcedResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
