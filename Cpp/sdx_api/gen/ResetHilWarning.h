#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset Hardware in the loop trajectory server warning message.
    ///
    /// 
    ///

    class ResetHilWarning;
    typedef std::shared_ptr<ResetHilWarning> ResetHilWarningPtr;
    
    
    class ResetHilWarning : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetHilWarning();
  
      static ResetHilWarningPtr create();
      static ResetHilWarningPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

