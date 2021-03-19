#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use SetNavICNavAlertFlagForSV.
    /// 
    /// Set NavIC NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------
    /// SvId  int  Satellite SV ID 1..14
    /// Alert bool NavIC NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetNavICSatelliteNavAlertFlag;
    typedef std::shared_ptr<SetNavICSatelliteNavAlertFlag> SetNavICSatelliteNavAlertFlagPtr;
    
    
    class SetNavICSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICSatelliteNavAlertFlag();

      SetNavICSatelliteNavAlertFlag(int svId, bool alert);
  
      static SetNavICSatelliteNavAlertFlagPtr create(int svId, bool alert);
      static SetNavICSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
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

