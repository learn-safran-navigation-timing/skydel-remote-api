
#include "gen/SetConfigBroadcastOnStart.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConfigBroadcastOnStart
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConfigBroadcastOnStart::CmdName = "SetConfigBroadcastOnStart";
    const char* const SetConfigBroadcastOnStart::Documentation = "Set wether the main instance should send its configuration to every worker instance when simulation start.";

    REGISTER_COMMAND_FACTORY(SetConfigBroadcastOnStart);


    SetConfigBroadcastOnStart::SetConfigBroadcastOnStart()
      : CommandBase(CmdName)
    {}

    SetConfigBroadcastOnStart::SetConfigBroadcastOnStart(bool broadcastOnStart)
      : CommandBase(CmdName)
    {

      setBroadcastOnStart(broadcastOnStart);
    }

    SetConfigBroadcastOnStartPtr SetConfigBroadcastOnStart::create(bool broadcastOnStart)
    {
      return std::make_shared<SetConfigBroadcastOnStart>(broadcastOnStart);
    }

    SetConfigBroadcastOnStartPtr SetConfigBroadcastOnStart::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetConfigBroadcastOnStart>(ptr);
    }

    bool SetConfigBroadcastOnStart::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["BroadcastOnStart"])
        ;

    }

    std::string SetConfigBroadcastOnStart::documentation() const { return Documentation; }


    int SetConfigBroadcastOnStart::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool SetConfigBroadcastOnStart::broadcastOnStart() const
    {
      return parse_json<bool>::parse(m_values["BroadcastOnStart"]);
    }

    void SetConfigBroadcastOnStart::setBroadcastOnStart(bool broadcastOnStart)
    {
      m_values.AddMember("BroadcastOnStart", parse_json<bool>::format(broadcastOnStart, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
