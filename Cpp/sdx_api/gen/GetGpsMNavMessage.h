#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsMNavMessage is deprecated since 21.3. You may use GetMessageModificationToGpsMNav.
    /// 
    /// Get infos about the MNAV Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------
    /// Id   string Unique identifier of the event to get.
    ///

    class GetGpsMNavMessage;
    typedef std::shared_ptr<GetGpsMNavMessage> GetGpsMNavMessagePtr;
    
    
    class GetGpsMNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsMNavMessage();

      GetGpsMNavMessage(const std::string& id);
  
      static GetGpsMNavMessagePtr create(const std::string& id);
      static GetGpsMNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

