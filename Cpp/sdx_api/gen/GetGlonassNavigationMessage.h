#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ModificationToGlonassNavigationMessage is deprecated since 21.3. You may use MessageModificationToGlonassNav.
    /// 
    /// Get infos about this modification Glonass navigation message event
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetGlonassNavigationMessage;
    typedef std::shared_ptr<GetGlonassNavigationMessage> GetGlonassNavigationMessagePtr;
    
    
    class GetGlonassNavigationMessage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassNavigationMessage();

      GetGlonassNavigationMessage(const std::string& id);
  
      static GetGlonassNavigationMessagePtr create(const std::string& id);
      static GetGlonassNavigationMessagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

