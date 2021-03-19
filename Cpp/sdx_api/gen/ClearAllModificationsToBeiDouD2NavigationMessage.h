#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToBeiDouD2NavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change BeiDou navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToBeiDouD2NavigationMessage;
    typedef std::shared_ptr<ClearAllModificationsToBeiDouD2NavigationMessage> ClearAllModificationsToBeiDouD2NavigationMessagePtr;
    
    
    class ClearAllModificationsToBeiDouD2NavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToBeiDouD2NavigationMessage();
  
      static ClearAllModificationsToBeiDouD2NavigationMessagePtr create();
      static ClearAllModificationsToBeiDouD2NavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

