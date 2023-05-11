
#include "gen/CancelBroadcastConfig.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of CancelBroadcastConfig
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const CancelBroadcastConfig::CmdName = "CancelBroadcastConfig";
    const char* const CancelBroadcastConfig::Documentation = "Cancel the current configuration broadcast if any.";

    REGISTER_COMMAND_FACTORY(CancelBroadcastConfig);


    CancelBroadcastConfig::CancelBroadcastConfig()
      : CommandBase(CmdName)
    {

    }

    CancelBroadcastConfigPtr CancelBroadcastConfig::create()
    {
      return std::make_shared<CancelBroadcastConfig>();
    }

    CancelBroadcastConfigPtr CancelBroadcastConfig::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<CancelBroadcastConfig>(ptr);
    }

    bool CancelBroadcastConfig::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string CancelBroadcastConfig::documentation() const { return Documentation; }


    int CancelBroadcastConfig::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
