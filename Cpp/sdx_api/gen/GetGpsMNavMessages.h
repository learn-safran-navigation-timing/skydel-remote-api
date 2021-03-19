#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsMNavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the GPS MNav Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsMNavMessages;
    typedef std::shared_ptr<GetGpsMNavMessages> GetGpsMNavMessagesPtr;
    
    
    class GetGpsMNavMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsMNavMessages();

      GetGpsMNavMessages(int prn);
  
      static GetGpsMNavMessagesPtr create(int prn);
      static GetGpsMNavMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

