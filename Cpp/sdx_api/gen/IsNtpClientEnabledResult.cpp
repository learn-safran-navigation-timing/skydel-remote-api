
#include "IsNtpClientEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsNtpClientEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsNtpClientEnabledResult::CmdName = "IsNtpClientEnabledResult";
    const char* const IsNtpClientEnabledResult::Documentation = "Result of IsNtpClientEnabled.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- --------------------------------------------------------------------------------\n"
      "Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.";
    const char* const IsNtpClientEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsNtpClientEnabledResult);


    IsNtpClientEnabledResult::IsNtpClientEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsNtpClientEnabledResult::IsNtpClientEnabledResult(bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    IsNtpClientEnabledResult::IsNtpClientEnabledResult(CommandBasePtr relatedCommand, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
    }


    IsNtpClientEnabledResultPtr IsNtpClientEnabledResult::create(bool enabled)
    {
      return std::make_shared<IsNtpClientEnabledResult>(enabled);
    }

    IsNtpClientEnabledResultPtr IsNtpClientEnabledResult::create(CommandBasePtr relatedCommand, bool enabled)
    {
      return std::make_shared<IsNtpClientEnabledResult>(relatedCommand, enabled);
    }

    IsNtpClientEnabledResultPtr IsNtpClientEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsNtpClientEnabledResult>(ptr);
    }

    bool IsNtpClientEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsNtpClientEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsNtpClientEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    bool IsNtpClientEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsNtpClientEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
