#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICNavAlertFlagForSV
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------
    /// SvId  int  Satellite SV ID 1..14
    /// Alert bool NavIC NAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetNavICNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetNavICNavAlertFlagForSVResult> GetNavICNavAlertFlagForSVResultPtr;
    typedef GetNavICNavAlertFlagForSVResult GetNavICSatelliteNavAlertFlagResult;
    typedef std::shared_ptr<GetNavICSatelliteNavAlertFlagResult> GetNavICSatelliteNavAlertFlagResultPtr;
    
    class GetNavICNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICNavAlertFlagForSVResult();

      GetNavICNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert);
  
      static GetNavICNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert);
      static GetNavICNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);
    };
  }
}

