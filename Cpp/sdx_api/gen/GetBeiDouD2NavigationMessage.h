#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouD2NavigationMessage is deprecated since 21.3. You may use GetMessageModificationToBeiDouD2Nav.
    /// 
    /// Get infos about this modification BeiDou D2 navigation message event
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetBeiDouD2NavigationMessage;
    typedef std::shared_ptr<GetBeiDouD2NavigationMessage> GetBeiDouD2NavigationMessagePtr;
    
    
    class GetBeiDouD2NavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD2NavigationMessage();

      GetBeiDouD2NavigationMessage(const std::string& id);
  
      static GetBeiDouD2NavigationMessagePtr create(const std::string& id);
      static GetBeiDouD2NavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

