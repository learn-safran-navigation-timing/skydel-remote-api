#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssSatelliteNavAlertFlag is deprecated since 21.3. You may use SetQzssNavAlertFlagForSV.
    /// 
    /// Set QZSS NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// SvId  int  Satellite SV ID 1..10
    /// Alert bool QZSS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetQzssSatelliteNavAlertFlag;
    typedef std::shared_ptr<SetQzssSatelliteNavAlertFlag> SetQzssSatelliteNavAlertFlagPtr;
    
    
    class SetQzssSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteNavAlertFlag();

      SetQzssSatelliteNavAlertFlag(int svId, bool alert);
  
      static SetQzssSatelliteNavAlertFlagPtr create(int svId, bool alert);
      static SetQzssSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
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

