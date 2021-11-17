#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsNavAlertFlagForSV.
    ///
    /// Name  Type Description
    /// ----- ---- --------------------------------------------------
    /// SvId  int  Satellite's SV ID 1..32
    /// Alert bool GPS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetGpsNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetGpsNavAlertFlagForSVResult> GetGpsNavAlertFlagForSVResultPtr;
    
    
    class GetGpsNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsNavAlertFlagForSVResult();

      GetGpsNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert);
  
      static GetGpsNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert);
      static GetGpsNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

