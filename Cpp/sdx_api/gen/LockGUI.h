#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Prevent GUI updates while modify the configuration. Use UnlockGUI when done with
    /// configuration modifications.
    ///
    /// 
    ///

    class LockGUI;
    typedef std::shared_ptr<LockGUI> LockGUIPtr;
    
    
    class LockGUI : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      LockGUI();

      static LockGUIPtr create();
      static LockGUIPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

