
#include "RedoCmd.h"

#include "command_factory.h"
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
    const char* const RedoCmd::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RedoCmd);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RedoCmd);


    RedoCmd::RedoCmd()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& RedoCmd::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int RedoCmd::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
