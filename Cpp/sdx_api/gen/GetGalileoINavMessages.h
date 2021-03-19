#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoINavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the GALILEO INAV Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..36
    ///

    class GetGalileoINavMessages;
    typedef std::shared_ptr<GetGalileoINavMessages> GetGalileoINavMessagesPtr;
    
    
    class GetGalileoINavMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoINavMessages();

      GetGalileoINavMessages(int prn);
  
      static GetGalileoINavMessagesPtr create(int prn);
      static GetGalileoINavMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

