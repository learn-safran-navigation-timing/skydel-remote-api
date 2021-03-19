#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToGalileoINavMessage is deprecated since 21.3. You may use MessageModificationToGalileoINav.
    /// 
    /// Get infos about the INAV Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGalileoINavMessage;
    typedef std::shared_ptr<GetGalileoINavMessage> GetGalileoINavMessagePtr;
    
    
    class GetGalileoINavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoINavMessage();

      GetGalileoINavMessage(const std::string& id);
  
      static GetGalileoINavMessagePtr create(const std::string& id);
      static GetGalileoINavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

