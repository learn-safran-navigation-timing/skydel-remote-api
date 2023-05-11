
#include "gen/GetConfigBroadcastOnStart.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastOnStart
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastOnStart::CmdName = "GetConfigBroadcastOnStart";
    const char* const GetConfigBroadcastOnStart::Documentation = "Get wether the master should send its configuration to every slave when simulation start.";

    REGISTER_COMMAND_FACTORY(GetConfigBroadcastOnStart);


    GetConfigBroadcastOnStart::GetConfigBroadcastOnStart()
      : CommandBase(CmdName)
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


    int GetConfigBroadcastOnStart::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
