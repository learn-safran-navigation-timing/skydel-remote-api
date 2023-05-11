#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Resume GUI updates and force one update immediately.
    ///
    /// 
    ///

    class UnlockGUI;
    typedef std::shared_ptr<UnlockGUI> UnlockGUIPtr;
    
    
    class UnlockGUI : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      UnlockGUI();

      static UnlockGUIPtr create();
      static UnlockGUIPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

