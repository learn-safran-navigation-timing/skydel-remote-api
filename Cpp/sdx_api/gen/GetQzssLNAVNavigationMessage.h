#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssLNAVNavigationMessage is deprecated since 21.3. You may use GetMessageModificationToQzssLNav.
    /// 
    /// Get infos about this modification QZSS navigation message event.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetQzssLNAVNavigationMessage;
    typedef std::shared_ptr<GetQzssLNAVNavigationMessage> GetQzssLNAVNavigationMessagePtr;
    
    
    class GetQzssLNAVNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssLNAVNavigationMessage();

      GetQzssLNAVNavigationMessage(const std::string& id);
  
      static GetQzssLNAVNavigationMessagePtr create(const std::string& id);
      static GetQzssLNAVNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

