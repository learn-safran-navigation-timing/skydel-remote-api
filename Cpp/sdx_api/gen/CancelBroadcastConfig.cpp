
#include "CancelBroadcastConfig.h"

#include "command_factory.h"
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
    const char* const CancelBroadcastConfig::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(CancelBroadcastConfig);
    REGISTER_COMMAND_TO_FACTORY_IMPL(CancelBroadcastConfig);


    CancelBroadcastConfig::CancelBroadcastConfig()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& CancelBroadcastConfig::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int CancelBroadcastConfig::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
