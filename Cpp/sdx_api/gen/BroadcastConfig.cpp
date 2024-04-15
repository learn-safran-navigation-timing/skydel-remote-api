
#include "BroadcastConfig.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of BroadcastConfig
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BroadcastConfig::CmdName = "BroadcastConfig";
    const char* const BroadcastConfig::Documentation = "Ask the main instance to broadcast its configuration to all worker instances.";
    const char* const BroadcastConfig::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(BroadcastConfig);
    REGISTER_COMMAND_TO_FACTORY_IMPL(BroadcastConfig);


    BroadcastConfig::BroadcastConfig()
      : CommandBase(CmdName, TargetId)
    {

    }

    BroadcastConfigPtr BroadcastConfig::create()
    {
      return std::make_shared<BroadcastConfig>();
    }

    BroadcastConfigPtr BroadcastConfig::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<BroadcastConfig>(ptr);
    }

    bool BroadcastConfig::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string BroadcastConfig::documentation() const { return Documentation; }

    const std::vector<std::string>& BroadcastConfig::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int BroadcastConfig::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
