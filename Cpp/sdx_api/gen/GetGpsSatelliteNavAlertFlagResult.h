#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteNavAlertFlag
    ///
    /// Name  Type Description
    /// ----- ---- --------------------------------------------------
    /// Prn   int  Satellite PRN number 1..32
    /// Alert bool GPS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetGpsSatelliteNavAlertFlagResult;
    typedef std::shared_ptr<GetGpsSatelliteNavAlertFlagResult> GetGpsSatelliteNavAlertFlagResultPtr;
    
    
    class GetGpsSatelliteNavAlertFlagResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteNavAlertFlagResult();

      GetGpsSatelliteNavAlertFlagResult(CommandBasePtr relatedCommand, int prn, bool alert);
  
      static GetGpsSatelliteNavAlertFlagResultPtr create(CommandBasePtr relatedCommand, int prn, bool alert);
      static GetGpsSatelliteNavAlertFlagResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);
    };
  }
}

