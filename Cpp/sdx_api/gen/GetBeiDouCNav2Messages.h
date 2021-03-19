#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouCNav2Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the BeiDou CNAV2 Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouCNav2Messages;
    typedef std::shared_ptr<GetBeiDouCNav2Messages> GetBeiDouCNav2MessagesPtr;
    
    
    class GetBeiDouCNav2Messages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav2Messages();

      GetBeiDouCNav2Messages(int prn);
  
      static GetBeiDouCNav2MessagesPtr create(int prn);
      static GetBeiDouCNav2MessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

