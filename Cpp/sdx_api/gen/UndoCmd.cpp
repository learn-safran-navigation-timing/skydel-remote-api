
#include "gen/UndoCmd.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of UndoCmd
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const UndoCmd::CmdName = "UndoCmd";
    const char* const UndoCmd::Documentation = "Undo the last command like Ctrl+Z in the UI";

    REGISTER_COMMAND_FACTORY(UndoCmd);


    UndoCmd::UndoCmd()
      : CommandBase(CmdName)
    {

    }

    UndoCmdPtr UndoCmd::create()
    {
      return std::make_shared<UndoCmd>();
    }

    UndoCmdPtr UndoCmd::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<UndoCmd>(ptr);
    }

    bool UndoCmd::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string UndoCmd::documentation() const { return Documentation; }


    int UndoCmd::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
