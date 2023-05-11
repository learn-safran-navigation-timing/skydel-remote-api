
#include "gen/BroadcastConfig.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of BroadcastConfig
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const BroadcastConfig::CmdName = "BroadcastConfig";
    const char* const BroadcastConfig::Documentation = "Ask the master to broadcast its configuration to all slaves.";

    REGISTER_COMMAND_FACTORY(BroadcastConfig);


    BroadcastConfig::BroadcastConfig()
      : CommandBase(CmdName)
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


    int BroadcastConfig::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
