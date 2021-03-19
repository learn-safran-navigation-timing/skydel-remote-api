#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToBeiDouCNav1Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change BeiDou navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToBeiDouCNav1Message;
    typedef std::shared_ptr<ClearAllModificationsToBeiDouCNav1Message> ClearAllModificationsToBeiDouCNav1MessagePtr;
    
    
    class ClearAllModificationsToBeiDouCNav1Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToBeiDouCNav1Message();
  
      static ClearAllModificationsToBeiDouCNav1MessagePtr create();
      static ClearAllModificationsToBeiDouCNav1MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

