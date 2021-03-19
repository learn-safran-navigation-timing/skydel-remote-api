#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToGpsCNav2Message is deprecated since 21.3. You may use MessageModificationToGpsCNav2.
    /// 
    /// Get infos about the CNAV2 Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGpsCNav2Message;
    typedef std::shared_ptr<GetGpsCNav2Message> GetGpsCNav2MessagePtr;
    
    
    class GetGpsCNav2Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNav2Message();

      GetGpsCNav2Message(const std::string& id);
  
      static GetGpsCNav2MessagePtr create(const std::string& id);
      static GetGpsCNav2MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

