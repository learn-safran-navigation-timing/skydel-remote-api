
#include "EnablePlugin.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePlugin
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePlugin::CmdName = "EnablePlugin";
    const char* const EnablePlugin::Documentation = "Enable a plug-in for the whole system.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "Id      string Plug-in ID.\n"
      "Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).";
    const char* const EnablePlugin::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnablePlugin);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnablePlugin);


    EnablePlugin::EnablePlugin()
      : CommandBase(CmdName, TargetId)
    {}

    EnablePlugin::EnablePlugin(const std::string& id, bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
      setEnabled(enabled);
    }

    EnablePluginPtr EnablePlugin::create(const std::string& id, bool enabled)
    {
      return std::make_shared<EnablePlugin>(id, enabled);
    }

    EnablePluginPtr EnablePlugin::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePlugin>(ptr);
    }

    bool EnablePlugin::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePlugin::documentation() const { return Documentation; }

    const std::vector<std::string>& EnablePlugin::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id", "Enabled"}; 
      return names; 
    }


    int EnablePlugin::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string EnablePlugin::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnablePlugin::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnablePlugin::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnablePlugin::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
