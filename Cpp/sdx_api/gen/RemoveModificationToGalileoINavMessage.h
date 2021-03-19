#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToGalileoINavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes a modification.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Id   string Unique identifier (see SetModificationToGalileoINavMessage)
    ///

    class RemoveModificationToGalileoINavMessage;
    typedef std::shared_ptr<RemoveModificationToGalileoINavMessage> RemoveModificationToGalileoINavMessagePtr;
    
    
    class RemoveModificationToGalileoINavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToGalileoINavMessage();

      RemoveModificationToGalileoINavMessage(const std::string& id);
  
      static RemoveModificationToGalileoINavMessagePtr create(const std::string& id);
      static RemoveModificationToGalileoINavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

