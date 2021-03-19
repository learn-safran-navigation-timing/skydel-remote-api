#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToBeiDouCNav2Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes a BeiDou CNAV2 modification.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Id   string Unique identifier (see SetModificationToBeiDouCNav2Message)
    ///

    class RemoveModificationToBeiDouCNav2Message;
    typedef std::shared_ptr<RemoveModificationToBeiDouCNav2Message> RemoveModificationToBeiDouCNav2MessagePtr;
    
    
    class RemoveModificationToBeiDouCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToBeiDouCNav2Message();

      RemoveModificationToBeiDouCNav2Message(const std::string& id);
  
      static RemoveModificationToBeiDouCNav2MessagePtr create(const std::string& id);
      static RemoveModificationToBeiDouCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

