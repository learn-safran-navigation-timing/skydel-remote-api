
#include "GetConfigBroadcastOnStartResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastOnStartResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastOnStartResult::CmdName = "GetConfigBroadcastOnStartResult";
    const char* const GetConfigBroadcastOnStartResult::Documentation = "Result of GetConfigBroadcastOnStart.\n"
      "\n"
      "Name             Type Description\n"
      "---------------- ---- --------------------------------------------------------------\n"
      "BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.";
    const char* const GetConfigBroadcastOnStartResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConfigBroadcastOnStartResult);


    GetConfigBroadcastOnStartResult::GetConfigBroadcastOnStartResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetConfigBroadcastOnStartResult::GetConfigBroadcastOnStartResult(bool broadcastOnStart)
      : CommandResult(CmdName, TargetId)
    {

      setBroadcastOnStart(broadcastOnStart);
    }

    GetConfigBroadcastOnStartResult::GetConfigBroadcastOnStartResult(CommandBasePtr relatedCommand, bool broadcastOnStart)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setBroadcastOnStart(broadcastOnStart);
    }


    GetConfigBroadcastOnStartResultPtr GetConfigBroadcastOnStartResult::create(bool broadcastOnStart)
    {
      return std::make_shared<GetConfigBroadcastOnStartResult>(broadcastOnStart);
    }

    GetConfigBroadcastOnStartResultPtr GetConfigBroadcastOnStartResult::create(CommandBasePtr relatedCommand, bool broadcastOnStart)
    {
      return std::make_shared<GetConfigBroadcastOnStartResult>(relatedCommand, broadcastOnStart);
    }

    GetConfigBroadcastOnStartResultPtr GetConfigBroadcastOnStartResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigBroadcastOnStartResult>(ptr);
    }

    bool GetConfigBroadcastOnStartResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["BroadcastOnStart"])
        ;

    }

    std::string GetConfigBroadcastOnStartResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConfigBroadcastOnStartResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"BroadcastOnStart"}; 
      return names; 
    }


    bool GetConfigBroadcastOnStartResult::broadcastOnStart() const
    {
      return parse_json<bool>::parse(m_values["BroadcastOnStart"]);
    }

    void GetConfigBroadcastOnStartResult::setBroadcastOnStart(bool broadcastOnStart)
    {
      m_values.AddMember("BroadcastOnStart", parse_json<bool>::format(broadcastOnStart, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
