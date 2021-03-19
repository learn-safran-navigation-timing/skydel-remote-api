#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToBeiDouD1NavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change BeiDou navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToBeiDouD1NavigationMessage;
    typedef std::shared_ptr<ClearAllModificationsToBeiDouD1NavigationMessage> ClearAllModificationsToBeiDouD1NavigationMessagePtr;
    
    
    class ClearAllModificationsToBeiDouD1NavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToBeiDouD1NavigationMessage();
  
      static ClearAllModificationsToBeiDouD1NavigationMessagePtr create();
      static ClearAllModificationsToBeiDouD1NavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

