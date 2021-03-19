#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteCNavAlertFlag is deprecated since 21.3. You may use GpsCNavAlertFlagToSV.
    /// 
    /// Set GPS CNAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// Prn   int  Satellite PRN number 1..32
    /// Alert bool GPS CNAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetGpsSatelliteCNavAlertFlag;
    typedef std::shared_ptr<SetGpsSatelliteCNavAlertFlag> SetGpsSatelliteCNavAlertFlagPtr;
    
    
    class SetGpsSatelliteCNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteCNavAlertFlag();

      SetGpsSatelliteCNavAlertFlag(int prn, bool alert);
  
      static SetGpsSatelliteCNavAlertFlagPtr create(int prn, bool alert);
      static SetGpsSatelliteCNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
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

