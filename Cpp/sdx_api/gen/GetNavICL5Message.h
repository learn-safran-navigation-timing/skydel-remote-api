#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetNavICL5Message is deprecated since 21.3. You may use GetMessageModificationToNavICNav.
    /// 
    /// Get infos about the NAV Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetNavICL5Message;
    typedef std::shared_ptr<GetNavICL5Message> GetNavICL5MessagePtr;
    
    
    class GetNavICL5Message : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICL5Message();

      GetNavICL5Message(const std::string& id);
  
      static GetNavICL5MessagePtr create(const std::string& id);
      static GetNavICL5MessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

