#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set NavIC NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------
    /// SvId  int  Satellite SV ID 1..14
    /// Alert bool NavIC NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetNavICNavAlertFlagForSV;
    typedef std::shared_ptr<SetNavICNavAlertFlagForSV> SetNavICNavAlertFlagForSVPtr;
    
    
    class SetNavICNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICNavAlertFlagForSV();

      SetNavICNavAlertFlagForSV(int svId, bool alert);
  
      static SetNavICNavAlertFlagForSVPtr create(int svId, bool alert);
      static SetNavICNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);
    };
  }
}

