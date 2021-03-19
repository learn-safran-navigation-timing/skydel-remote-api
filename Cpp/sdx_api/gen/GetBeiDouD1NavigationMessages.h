#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouD1NavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the BeiDou D1 Navigation Messages for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..24
    ///

    class GetBeiDouD1NavigationMessages;
    typedef std::shared_ptr<GetBeiDouD1NavigationMessages> GetBeiDouD1NavigationMessagesPtr;
    
    
    class GetBeiDouD1NavigationMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouD1NavigationMessages();

      GetBeiDouD1NavigationMessages(int prn);
  
      static GetBeiDouD1NavigationMessagesPtr create(int prn);
      static GetBeiDouD1NavigationMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

