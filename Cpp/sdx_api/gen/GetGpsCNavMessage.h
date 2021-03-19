#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToGpsCNavMessage is deprecated since 21.3. You may use MessageModificationToGpsCNav.
    /// 
    /// Get infos about the CNAV Message with this id
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGpsCNavMessage;
    typedef std::shared_ptr<GetGpsCNavMessage> GetGpsCNavMessagePtr;
    
    
    class GetGpsCNavMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNavMessage();

      GetGpsCNavMessage(const std::string& id);
  
      static GetGpsCNavMessagePtr create(const std::string& id);
      static GetGpsCNavMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

