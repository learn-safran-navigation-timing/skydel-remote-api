#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToGlonassNavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes an event added with SetModificationToGlonassNavigationMessage. When adding an event, the simulator
    /// sets the Id parameter. Use that Id here to remove the associated event.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------
    /// Id   string Unique identifier of the event to remove.
    ///

    class RemoveModificationToGlonassNavigationMessage;
    typedef std::shared_ptr<RemoveModificationToGlonassNavigationMessage> RemoveModificationToGlonassNavigationMessagePtr;
    
    
    class RemoveModificationToGlonassNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToGlonassNavigationMessage();

      RemoveModificationToGlonassNavigationMessage(const std::string& id);
  
      static RemoveModificationToGlonassNavigationMessagePtr create(const std::string& id);
      static RemoveModificationToGlonassNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

