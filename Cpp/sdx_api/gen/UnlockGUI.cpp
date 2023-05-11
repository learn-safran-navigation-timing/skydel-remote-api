
#include "gen/UnlockGUI.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of UnlockGUI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const UnlockGUI::CmdName = "UnlockGUI";
    const char* const UnlockGUI::Documentation = "Resume GUI updates and force one update immediately.";

    REGISTER_COMMAND_FACTORY(UnlockGUI);


    UnlockGUI::UnlockGUI()
      : CommandBase(CmdName)
    {

    }

    UnlockGUIPtr UnlockGUI::create()
    {
      return std::make_shared<UnlockGUI>();
    }

    UnlockGUIPtr UnlockGUI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<UnlockGUI>(ptr);
    }

    bool UnlockGUI::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string UnlockGUI::documentation() const { return Documentation; }


    int UnlockGUI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
