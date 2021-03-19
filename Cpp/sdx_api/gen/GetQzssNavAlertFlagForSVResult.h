#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssNavAlertFlagForSV
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// SvId  int  Satellite SV ID 1..10
    /// Alert bool QZSS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetQzssNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetQzssNavAlertFlagForSVResult> GetQzssNavAlertFlagForSVResultPtr;
    typedef GetQzssNavAlertFlagForSVResult GetQzssSatelliteNavAlertFlagResult;
    typedef std::shared_ptr<GetQzssSatelliteNavAlertFlagResult> GetQzssSatelliteNavAlertFlagResultPtr;
    
    class GetQzssNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssNavAlertFlagForSVResult();

      GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert);
  
      static GetQzssNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert);
      static GetQzssNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

