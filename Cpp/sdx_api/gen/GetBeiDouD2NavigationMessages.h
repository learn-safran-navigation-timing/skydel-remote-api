#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouD2NavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the BeiDou D2 Navigation Messages for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..24
    ///

    class GetBeiDouD2NavigationMessages;
    typedef std::shared_ptr<GetBeiDouD2NavigationMessages> GetBeiDouD2NavigationMessagesPtr;
    
    
    class GetBeiDouD2NavigationMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD2NavigationMessages();

      GetBeiDouD2NavigationMessages(int prn);
  
      static GetBeiDouD2NavigationMessagesPtr create(int prn);
      static GetBeiDouD2NavigationMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

