#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToBeiDouCNav1Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes a modification.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Id   string Unique identifier (see SetModificationToBeiDouCNav1Message)
    ///

    class RemoveModificationToBeiDouCNav1Message;
    typedef std::shared_ptr<RemoveModificationToBeiDouCNav1Message> RemoveModificationToBeiDouCNav1MessagePtr;
    
    
    class RemoveModificationToBeiDouCNav1Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToBeiDouCNav1Message();

      RemoveModificationToBeiDouCNav1Message(const std::string& id);
  
      static RemoveModificationToBeiDouCNav1MessagePtr create(const std::string& id);
      static RemoveModificationToBeiDouCNav1MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

