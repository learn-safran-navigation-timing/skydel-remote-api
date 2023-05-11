#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetLastHilWarning is deprecated since 22.5. You may use GetHilExtrapolationState.
    /// 
    /// Get last Hardware in the loop trajectory server warning message. Returns HilWarningResult.
    ///
    /// 
    ///

    class GetLastHilWarning;
    typedef std::shared_ptr<GetLastHilWarning> GetLastHilWarningPtr;
    
    
    class GetLastHilWarning : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetLastHilWarning();

      static GetLastHilWarningPtr create();
      static GetLastHilWarningPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

