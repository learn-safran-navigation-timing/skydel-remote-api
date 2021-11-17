#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteCNavAlertFlag.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// Prn   int  Satellite PRN number 1..32
    /// Alert bool GPS CNAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetGpsSatelliteCNavAlertFlagResult;
    typedef std::shared_ptr<GetGpsSatelliteCNavAlertFlagResult> GetGpsSatelliteCNavAlertFlagResultPtr;
    
    
    class GetGpsSatelliteCNavAlertFlagResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteCNavAlertFlagResult();

      GetGpsSatelliteCNavAlertFlagResult(CommandBasePtr relatedCommand, int prn, bool alert);
  
      static GetGpsSatelliteCNavAlertFlagResultPtr create(CommandBasePtr relatedCommand, int prn, bool alert);
      static GetGpsSatelliteCNavAlertFlagResultPtr dynamicCast(CommandBasePtr ptr);
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

