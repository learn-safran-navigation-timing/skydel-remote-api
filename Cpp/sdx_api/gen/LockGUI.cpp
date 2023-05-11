
#include "gen/LockGUI.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of LockGUI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const LockGUI::CmdName = "LockGUI";
    const char* const LockGUI::Documentation = "Prevent GUI updates while modify the configuration. Use UnlockGUI when done with\nconfiguration modifications.";

    REGISTER_COMMAND_FACTORY(LockGUI);


    LockGUI::LockGUI()
      : CommandBase(CmdName)
    {

    }

    LockGUIPtr LockGUI::create()
    {
      return std::make_shared<LockGUI>();
    }

    LockGUIPtr LockGUI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<LockGUI>(ptr);
    }

    bool LockGUI::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string LockGUI::documentation() const { return Documentation; }


    int LockGUI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
