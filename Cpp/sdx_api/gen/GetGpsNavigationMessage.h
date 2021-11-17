#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsNavigationMessage is deprecated since 21.3. You may use GetMessageModificationToGpsLNav.
    /// 
    /// Get infos about this modification gps navigation message event.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGpsNavigationMessage;
    typedef std::shared_ptr<GetGpsNavigationMessage> GetGpsNavigationMessagePtr;
    
    
    class GetGpsNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsNavigationMessage();

      GetGpsNavigationMessage(const std::string& id);
  
      static GetGpsNavigationMessagePtr create(const std::string& id);
      static GetGpsNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

