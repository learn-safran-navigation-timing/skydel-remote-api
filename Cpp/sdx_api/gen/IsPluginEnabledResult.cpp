
#include "IsPluginEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPluginEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPluginEnabledResult::CmdName = "IsPluginEnabledResult";
    const char* const IsPluginEnabledResult::Documentation = "Result of IsPluginEnabled.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "Id      string Plug-in ID.\n"
      "Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).";
    const char* const IsPluginEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPluginEnabledResult);


    IsPluginEnabledResult::IsPluginEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsPluginEnabledResult::IsPluginEnabledResult(const std::string& id, bool enabled)
      : CommandResult(CmdName, TargetId)
    {

      setId(id);
      setEnabled(enabled);
    }

    IsPluginEnabledResult::IsPluginEnabledResult(CommandBasePtr relatedCommand, const std::string& id, bool enabled)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setId(id);
      setEnabled(enabled);
    }


    IsPluginEnabledResultPtr IsPluginEnabledResult::create(const std::string& id, bool enabled)
    {
      return std::make_shared<IsPluginEnabledResult>(id, enabled);
    }

    IsPluginEnabledResultPtr IsPluginEnabledResult::create(CommandBasePtr relatedCommand, const std::string& id, bool enabled)
    {
      return std::make_shared<IsPluginEnabledResult>(relatedCommand, id, enabled);
    }

    IsPluginEnabledResultPtr IsPluginEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPluginEnabledResult>(ptr);
    }

    bool IsPluginEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPluginEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPluginEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "Enabled"}; 
      return names; 
    }


    std::string IsPluginEnabledResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsPluginEnabledResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsPluginEnabledResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void IsPluginEnabledResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
