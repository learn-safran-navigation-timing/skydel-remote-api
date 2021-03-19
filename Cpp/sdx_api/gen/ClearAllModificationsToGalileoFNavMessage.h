#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGalileoFNavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GALILEO navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGalileoFNavMessage;
    typedef std::shared_ptr<ClearAllModificationsToGalileoFNavMessage> ClearAllModificationsToGalileoFNavMessagePtr;
    
    
    class ClearAllModificationsToGalileoFNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGalileoFNavMessage();
  
      static ClearAllModificationsToGalileoFNavMessagePtr create();
      static ClearAllModificationsToGalileoFNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

