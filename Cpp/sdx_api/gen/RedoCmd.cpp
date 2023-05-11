
#include "gen/RedoCmd.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RedoCmd
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RedoCmd::CmdName = "RedoCmd";
    const char* const RedoCmd::Documentation = "Redo the last undone command like Ctrl+Shift+Z in the UI";

    REGISTER_COMMAND_FACTORY(RedoCmd);


    RedoCmd::RedoCmd()
      : CommandBase(CmdName)
    {

    }

    RedoCmdPtr RedoCmd::create()
    {
      return std::make_shared<RedoCmd>();
    }

    RedoCmdPtr RedoCmd::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RedoCmd>(ptr);
    }

    bool RedoCmd::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string RedoCmd::documentation() const { return Documentation; }


    int RedoCmd::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
