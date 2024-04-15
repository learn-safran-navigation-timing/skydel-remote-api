
#include "SetConfigBroadcastOnStart.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConfigBroadcastOnStart
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConfigBroadcastOnStart::CmdName = "SetConfigBroadcastOnStart";
    const char* const SetConfigBroadcastOnStart::Documentation = "Set whether the main instance should send its configuration to every worker instance when simulation start.\n"
      "\n"
      "Name             Type Description\n"
      "---------------- ---- --------------------------------------------------------------\n"
      "BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.";
    const char* const SetConfigBroadcastOnStart::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetConfigBroadcastOnStart);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetConfigBroadcastOnStart);


    SetConfigBroadcastOnStart::SetConfigBroadcastOnStart()
      : CommandBase(CmdName, TargetId)
    {}

    SetConfigBroadcastOnStart::SetConfigBroadcastOnStart(bool broadcastOnStart)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetConfigBroadcastOnStart::fieldNames() const 
    { 
      static const std::vector<std::string> names {"BroadcastOnStart"}; 
      return names; 
    }


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
