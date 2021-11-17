#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoFNavMessage is deprecated since 21.3. You may use GetMessageModificationToGalileoFNav.
    /// 
    /// Get infos about the FNAV Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGalileoFNavMessage;
    typedef std::shared_ptr<GetGalileoFNavMessage> GetGalileoFNavMessagePtr;
    
    
    class GetGalileoFNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoFNavMessage();

      GetGalileoFNavMessage(const std::string& id);
  
      static GetGalileoFNavMessagePtr create(const std::string& id);
      static GetGalileoFNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

