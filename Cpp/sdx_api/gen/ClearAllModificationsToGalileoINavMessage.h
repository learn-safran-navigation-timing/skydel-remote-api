#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllModificationsToGalileoINavMessage is deprecated since 21.3. You may use ClearAllMessageModificationsForNavMsgFamily.
    /// 
    /// Clear all events to change GALILEO navigation message bits
    ///
    /// 
    ///

    class ClearAllModificationsToGalileoINavMessage;
    typedef std::shared_ptr<ClearAllModificationsToGalileoINavMessage> ClearAllModificationsToGalileoINavMessagePtr;
    
    
    class ClearAllModificationsToGalileoINavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllModificationsToGalileoINavMessage();
  
      static ClearAllModificationsToGalileoINavMessagePtr create();
      static ClearAllModificationsToGalileoINavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

