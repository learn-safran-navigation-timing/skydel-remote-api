#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToBeiDouCNav2Message is deprecated since 21.3. You may use MessageModificationToBeiDouCNav2.
    /// 
    /// Get infos about the modifications of CNAV2 Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetBeiDouCNav2Message;
    typedef std::shared_ptr<GetBeiDouCNav2Message> GetBeiDouCNav2MessagePtr;
    
    
    class GetBeiDouCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav2Message();

      GetBeiDouCNav2Message(const std::string& id);
  
      static GetBeiDouCNav2MessagePtr create(const std::string& id);
      static GetBeiDouCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

