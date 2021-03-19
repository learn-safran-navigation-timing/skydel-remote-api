#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsCNav2Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the GPS CNav2 Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsCNav2Messages;
    typedef std::shared_ptr<GetGpsCNav2Messages> GetGpsCNav2MessagesPtr;
    
    
    class GetGpsCNav2Messages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNav2Messages();

      GetGpsCNav2Messages(int prn);
  
      static GetGpsCNav2MessagesPtr create(int prn);
      static GetGpsCNav2MessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

