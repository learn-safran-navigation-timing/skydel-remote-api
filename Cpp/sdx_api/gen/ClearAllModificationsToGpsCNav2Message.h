#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGpsCNav2Message is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GPS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGpsCNav2Message;
    typedef std::shared_ptr<ClearAllModificationsToGpsCNav2Message> ClearAllModificationsToGpsCNav2MessagePtr;
    
    
    class ClearAllModificationsToGpsCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGpsCNav2Message();
  
      static ClearAllModificationsToGpsCNav2MessagePtr create();
      static ClearAllModificationsToGpsCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

