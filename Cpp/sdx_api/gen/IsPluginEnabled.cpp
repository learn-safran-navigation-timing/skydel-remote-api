
#include "IsPluginEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPluginEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPluginEnabled::CmdName = "IsPluginEnabled";
    const char* const IsPluginEnabled::Documentation = "Get whether a plug-in is enabled for the whole system.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------\n"
      "Id   string Plug-in ID.";
    const char* const IsPluginEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsPluginEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPluginEnabled);


    IsPluginEnabled::IsPluginEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsPluginEnabled::IsPluginEnabled(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsPluginEnabledPtr IsPluginEnabled::create(const std::string& id)
    {
      return std::make_shared<IsPluginEnabled>(id);
    }

    IsPluginEnabledPtr IsPluginEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPluginEnabled>(ptr);
    }

    bool IsPluginEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsPluginEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPluginEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsPluginEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsPluginEnabled::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsPluginEnabled::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
