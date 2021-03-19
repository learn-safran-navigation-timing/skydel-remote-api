#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetBeiDouCNav1Messages is deprecated since 21.3. You may use GetAllMessageModificationIdsForNavMsgFamily.
    /// 
    /// Get all events' IDs whose will modify the BeiDou CNav1 Message for this PRN
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..24
    ///

    class GetBeiDouCNav1Messages;
    typedef std::shared_ptr<GetBeiDouCNav1Messages> GetBeiDouCNav1MessagesPtr;
    
    
    class GetBeiDouCNav1Messages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNav1Messages();

      GetBeiDouCNav1Messages(int prn);
  
      static GetBeiDouCNav1MessagesPtr create(int prn);
      static GetBeiDouCNav1MessagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

