#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToQzssLNAVNavigationMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change QZSS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToQzssLNAVNavigationMessage;
    typedef std::shared_ptr<ClearAllModificationsToQzssLNAVNavigationMessage> ClearAllModificationsToQzssLNAVNavigationMessagePtr;
    
    
    class ClearAllModificationsToQzssLNAVNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToQzssLNAVNavigationMessage();
  
      static ClearAllModificationsToQzssLNAVNavigationMessagePtr create();
      static ClearAllModificationsToQzssLNAVNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

