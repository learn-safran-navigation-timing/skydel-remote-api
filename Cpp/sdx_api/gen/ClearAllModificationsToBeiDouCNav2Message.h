#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToBeiDouCNav2Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change BeiDou CNAV2 navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToBeiDouCNav2Message;
    typedef std::shared_ptr<ClearAllModificationsToBeiDouCNav2Message> ClearAllModificationsToBeiDouCNav2MessagePtr;
    
    
    class ClearAllModificationsToBeiDouCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToBeiDouCNav2Message();
  
      static ClearAllModificationsToBeiDouCNav2MessagePtr create();
      static ClearAllModificationsToBeiDouCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

