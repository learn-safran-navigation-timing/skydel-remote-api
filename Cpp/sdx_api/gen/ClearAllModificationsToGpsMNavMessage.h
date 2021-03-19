#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGpsMNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GPS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGpsMNavMessage;
    typedef std::shared_ptr<ClearAllModificationsToGpsMNavMessage> ClearAllModificationsToGpsMNavMessagePtr;
    
    
    class ClearAllModificationsToGpsMNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGpsMNavMessage();
  
      static ClearAllModificationsToGpsMNavMessagePtr create();
      static ClearAllModificationsToGpsMNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

