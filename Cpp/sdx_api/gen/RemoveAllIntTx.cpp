
#include "gen/RemoveAllIntTx.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllIntTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllIntTx::CmdName = "RemoveAllIntTx";
    const char* const RemoveAllIntTx::Documentation = "Remove all the interference transmitters.";

    REGISTER_COMMAND_FACTORY(RemoveAllIntTx);


    RemoveAllIntTx::RemoveAllIntTx()
      : CommandBase(CmdName)
    {

    }

    RemoveAllIntTxPtr RemoveAllIntTx::create()
    {
      return std::make_shared<RemoveAllIntTx>();
    }

    RemoveAllIntTxPtr RemoveAllIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllIntTx>(ptr);
    }

    bool RemoveAllIntTx::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RemoveAllIntTx::documentation() const { return Documentation; }


    int RemoveAllIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }

  }
}
