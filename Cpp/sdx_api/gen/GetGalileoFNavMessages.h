#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoFNavMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the GALILEO FNAV Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..36
    ///

    class GetGalileoFNavMessages;
    typedef std::shared_ptr<GetGalileoFNavMessages> GetGalileoFNavMessagesPtr;
    
    
    class GetGalileoFNavMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoFNavMessages();

      GetGalileoFNavMessages(int prn);
  
      static GetGalileoFNavMessagesPtr create(int prn);
      static GetGalileoFNavMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

