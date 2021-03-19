#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToBeiDouD2NavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes an event added with SetModificationToBeiDouNavigationMessage. When adding an event, the simulator
    /// sets the Id parameter. Use that Id here to remove the associated event.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------
    /// Id   string Unique identifier of the event to remove.
    ///

    class RemoveModificationToBeiDouD2NavigationMessage;
    typedef std::shared_ptr<RemoveModificationToBeiDouD2NavigationMessage> RemoveModificationToBeiDouD2NavigationMessagePtr;
    
    
    class RemoveModificationToBeiDouD2NavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToBeiDouD2NavigationMessage();

      RemoveModificationToBeiDouD2NavigationMessage(const std::string& id);
  
      static RemoveModificationToBeiDouD2NavigationMessagePtr create(const std::string& id);
      static RemoveModificationToBeiDouD2NavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

