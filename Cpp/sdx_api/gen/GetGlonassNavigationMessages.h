#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGlonassNavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the Glonass Navigation Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..24
    ///

    class GetGlonassNavigationMessages;
    typedef std::shared_ptr<GetGlonassNavigationMessages> GetGlonassNavigationMessagesPtr;
    
    
    class GetGlonassNavigationMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassNavigationMessages();

      GetGlonassNavigationMessages(int prn);
  
      static GetGlonassNavigationMessagesPtr create(int prn);
      static GetGlonassNavigationMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

