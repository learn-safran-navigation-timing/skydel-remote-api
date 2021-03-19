#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToBeiDouCNav1Message is deprecated since 21.3. You may use MessageModificationToBeiDouCNav1.
    /// 
    /// Get infos about the CNAV1 Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetBeiDouCNav1Message;
    typedef std::shared_ptr<GetBeiDouCNav1Message> GetBeiDouCNav1MessagePtr;
    
    
    class GetBeiDouCNav1Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav1Message();

      GetBeiDouCNav1Message(const std::string& id);
  
      static GetBeiDouCNav1MessagePtr create(const std::string& id);
      static GetBeiDouCNav1MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

