#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clears the status log
    ///
    /// 
    ///

    class ClearStatusLog;
    typedef std::shared_ptr<ClearStatusLog> ClearStatusLogPtr;
    
    
    class ClearStatusLog : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearStatusLog();

      static ClearStatusLogPtr create();
      static ClearStatusLogPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

