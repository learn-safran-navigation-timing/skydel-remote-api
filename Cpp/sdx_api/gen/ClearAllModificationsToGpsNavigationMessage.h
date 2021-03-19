#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGpsNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GPS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGpsNavigationMessage;
    typedef std::shared_ptr<ClearAllModificationsToGpsNavigationMessage> ClearAllModificationsToGpsNavigationMessagePtr;
    
    
    class ClearAllModificationsToGpsNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGpsNavigationMessage();
  
      static ClearAllModificationsToGpsNavigationMessagePtr create();
      static ClearAllModificationsToGpsNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

