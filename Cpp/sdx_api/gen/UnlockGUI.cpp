
#include "UnlockGUI.h"

#include "command_factory.h"
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
    const char* const UnlockGUI::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(UnlockGUI);
    REGISTER_COMMAND_TO_FACTORY_IMPL(UnlockGUI);


    UnlockGUI::UnlockGUI()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& UnlockGUI::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int UnlockGUI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
