#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- --------------------------------------------------
    /// SvId  int  Satellite's SV ID 1..32
    /// Alert bool GPS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetGpsNavAlertFlagForSV;
    typedef std::shared_ptr<SetGpsNavAlertFlagForSV> SetGpsNavAlertFlagForSVPtr;
    
    
    class SetGpsNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsNavAlertFlagForSV();

      SetGpsNavAlertFlagForSV(int svId, bool alert);
  
      static SetGpsNavAlertFlagForSVPtr create(int svId, bool alert);
      static SetGpsNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
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

