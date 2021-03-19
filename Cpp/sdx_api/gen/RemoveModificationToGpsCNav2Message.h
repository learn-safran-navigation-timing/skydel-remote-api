#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToGpsCNav2Message is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes a modification.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------------------------
    /// Id   string Unique identifier (see SetModificationToGpsCNav2Message)
    ///

    class RemoveModificationToGpsCNav2Message;
    typedef std::shared_ptr<RemoveModificationToGpsCNav2Message> RemoveModificationToGpsCNav2MessagePtr;
    
    
    class RemoveModificationToGpsCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToGpsCNav2Message();

      RemoveModificationToGpsCNav2Message(const std::string& id);
  
      static RemoveModificationToGpsCNav2MessagePtr create(const std::string& id);
      static RemoveModificationToGpsCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

