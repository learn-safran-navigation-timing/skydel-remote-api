#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Undo the last command like Ctrl+Z in the UI
    ///
    /// 
    ///

    class UndoCmd;
    typedef std::shared_ptr<UndoCmd> UndoCmdPtr;
    
    
    class UndoCmd : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      UndoCmd();

      static UndoCmdPtr create();
      static UndoCmdPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

