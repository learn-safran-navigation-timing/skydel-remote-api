#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToQzssL1SMessage is deprecated since 21.3. You may use MessageModificationToQzssSlas.
    /// 
    /// Get infos about the L1S Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetQzssL1SMessage;
    typedef std::shared_ptr<GetQzssL1SMessage> GetQzssL1SMessagePtr;
    
    
    class GetQzssL1SMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1SMessage();

      GetQzssL1SMessage(const std::string& id);
  
      static GetQzssL1SMessagePtr create(const std::string& id);
      static GetQzssL1SMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

