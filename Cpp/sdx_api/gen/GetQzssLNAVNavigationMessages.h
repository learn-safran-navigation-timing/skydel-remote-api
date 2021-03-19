#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssLNAVNavigationMessages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the QZSS Navigation Message for this SV ID
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssLNAVNavigationMessages;
    typedef std::shared_ptr<GetQzssLNAVNavigationMessages> GetQzssLNAVNavigationMessagesPtr;
    
    
    class GetQzssLNAVNavigationMessages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssLNAVNavigationMessages();

      GetQzssLNAVNavigationMessages(int svId);
  
      static GetQzssLNAVNavigationMessagesPtr create(int svId);
      static GetQzssLNAVNavigationMessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

