#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGpsCNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GPS navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGpsCNavMessage;
    typedef std::shared_ptr<ClearAllModificationsToGpsCNavMessage> ClearAllModificationsToGpsCNavMessagePtr;
    
    
    class ClearAllModificationsToGpsCNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGpsCNavMessage();
  
      static ClearAllModificationsToGpsCNavMessagePtr create();
      static ClearAllModificationsToGpsCNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

