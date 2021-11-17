#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteNavAlertFlag is deprecated since 21.3. You may use SetGpsNavAlertFlagForSV.
    /// 
    /// Set GPS NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- --------------------------------------------------
    /// Prn   int  Satellite PRN number 1..32
    /// Alert bool GPS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetGpsSatelliteNavAlertFlag;
    typedef std::shared_ptr<SetGpsSatelliteNavAlertFlag> SetGpsSatelliteNavAlertFlagPtr;
    
    
    class SetGpsSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteNavAlertFlag();

      SetGpsSatelliteNavAlertFlag(int prn, bool alert);
  
      static SetGpsSatelliteNavAlertFlagPtr create(int prn, bool alert);
      static SetGpsSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);
    };
  }
}

