#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.
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

      static const char* const Deprecated;


      ResetHilWarning();

      static ResetHilWarningPtr create();
      static ResetHilWarningPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

