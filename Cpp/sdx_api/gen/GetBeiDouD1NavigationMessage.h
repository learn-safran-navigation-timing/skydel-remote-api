#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouD1NavigationMessage is deprecated since 21.3. You may use GetMessageModificationToBeiDouD1Nav.
    /// 
    /// Get infos about this modification BeiDou D1 navigation message event
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetBeiDouD1NavigationMessage;
    typedef std::shared_ptr<GetBeiDouD1NavigationMessage> GetBeiDouD1NavigationMessagePtr;
    
    
    class GetBeiDouD1NavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD1NavigationMessage();

      GetBeiDouD1NavigationMessage(const std::string& id);
  
      static GetBeiDouD1NavigationMessagePtr create(const std::string& id);
      static GetBeiDouD1NavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

