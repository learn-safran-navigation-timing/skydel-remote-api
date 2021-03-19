#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToQzssLNAVNavigationMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes an event added with SetModificationToQzssLNAVNavigationMessage. When adding an event, the simulator
    /// sets the Id parameter. Use that Id here to remove the associated event.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------
    /// Id   string Unique identifier of the event to remove.
    ///

    class RemoveModificationToQzssLNAVNavigationMessage;
    typedef std::shared_ptr<RemoveModificationToQzssLNAVNavigationMessage> RemoveModificationToQzssLNAVNavigationMessagePtr;
    
    
    class RemoveModificationToQzssLNAVNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToQzssLNAVNavigationMessage();

      RemoveModificationToQzssLNAVNavigationMessage(const std::string& id);
  
      static RemoveModificationToQzssLNAVNavigationMessagePtr create(const std::string& id);
      static RemoveModificationToQzssLNAVNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

