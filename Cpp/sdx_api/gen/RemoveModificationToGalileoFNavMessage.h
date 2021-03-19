#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveModificationToGalileoFNavMessage is deprecated since 21.3. You may use RemoveMessageModificationForNavMsgFamily.
    /// 
    /// Removes a modification.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Id   string Unique identifier (see SetModificationToGalileoFNavMessage)
    ///

    class RemoveModificationToGalileoFNavMessage;
    typedef std::shared_ptr<RemoveModificationToGalileoFNavMessage> RemoveModificationToGalileoFNavMessagePtr;
    
    
    class RemoveModificationToGalileoFNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModificationToGalileoFNavMessage();

      RemoveModificationToGalileoFNavMessage(const std::string& id);
  
      static RemoveModificationToGalileoFNavMessagePtr create(const std::string& id);
      static RemoveModificationToGalileoFNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

