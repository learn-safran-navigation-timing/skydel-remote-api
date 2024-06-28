
#include "EnableNtpClient.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableNtpClient
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableNtpClient::CmdName = "EnableNtpClient";
    const char* const EnableNtpClient::Documentation = "Enable (or disable) connections to an NTP server.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- --------------------------------------------------------------------------------\n"
      "Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.";
    const char* const EnableNtpClient::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableNtpClient);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableNtpClient);


    EnableNtpClient::EnableNtpClient()
      : CommandBase(CmdName, TargetId)
    {}

    EnableNtpClient::EnableNtpClient(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableNtpClientPtr EnableNtpClient::create(bool enabled)
    {
      return std::make_shared<EnableNtpClient>(enabled);
    }

    EnableNtpClientPtr EnableNtpClient::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableNtpClient>(ptr);
    }

    bool EnableNtpClient::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableNtpClient::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableNtpClient::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableNtpClient::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableNtpClient::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableNtpClient::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
