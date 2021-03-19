#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGlonassNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GLONASS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGlonassNavigationMessage;
    typedef std::shared_ptr<ClearAllModificationsToGlonassNavigationMessage> ClearAllModificationsToGlonassNavigationMessagePtr;
    
    
    class ClearAllModificationsToGlonassNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGlonassNavigationMessage();
  
      static ClearAllModificationsToGlonassNavigationMessagePtr create();
      static ClearAllModificationsToGlonassNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

