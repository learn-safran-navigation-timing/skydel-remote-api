
#include "GetPlugins.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPlugins
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPlugins::CmdName = "GetPlugins";
    const char* const GetPlugins::Documentation = "Get all Plug-ins present on the system (regardless of state).";
    const char* const GetPlugins::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPlugins);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPlugins);


    GetPlugins::GetPlugins()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetPluginsPtr GetPlugins::create()
    {
      return std::make_shared<GetPlugins>();
    }

    GetPluginsPtr GetPlugins::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPlugins>(ptr);
    }

    bool GetPlugins::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetPlugins::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPlugins::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetPlugins::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
