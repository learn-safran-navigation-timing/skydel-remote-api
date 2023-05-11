#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Redo the last undone command like Ctrl+Shift+Z in the UI
    ///
    /// 
    ///

    class RedoCmd;
    typedef std::shared_ptr<RedoCmd> RedoCmdPtr;
    
    
    class RedoCmd : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RedoCmd();

      static RedoCmdPtr create();
      static RedoCmdPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

