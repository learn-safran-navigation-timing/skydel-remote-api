
#include "GetConfigBroadcastOnStart.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastOnStart
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastOnStart::CmdName = "GetConfigBroadcastOnStart";
    const char* const GetConfigBroadcastOnStart::Documentation = "Get whether the main instance should send its configuration to every worker instance when simulation start.";
    const char* const GetConfigBroadcastOnStart::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetConfigBroadcastOnStart);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigBroadcastOnStart);


    GetConfigBroadcastOnStart::GetConfigBroadcastOnStart()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetConfigBroadcastOnStartPtr GetConfigBroadcastOnStart::create()
    {
      return std::make_shared<GetConfigBroadcastOnStart>();
    }

    GetConfigBroadcastOnStartPtr GetConfigBroadcastOnStart::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigBroadcastOnStart>(ptr);
    }

    bool GetConfigBroadcastOnStart::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetConfigBroadcastOnStart::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConfigBroadcastOnStart::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetConfigBroadcastOnStart::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
