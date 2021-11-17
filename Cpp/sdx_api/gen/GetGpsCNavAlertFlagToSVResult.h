#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsCNavAlertFlagToSV.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// SvId  int  Satellite's SV ID 1..32
    /// Alert bool GPS CNAV Alert Flag, false = No Alert, true = Alert
    ///

    class GetGpsCNavAlertFlagToSVResult;
    typedef std::shared_ptr<GetGpsCNavAlertFlagToSVResult> GetGpsCNavAlertFlagToSVResultPtr;
    
    
    class GetGpsCNavAlertFlagToSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNavAlertFlagToSVResult();

      GetGpsCNavAlertFlagToSVResult(CommandBasePtr relatedCommand, int svId, bool alert);
  
      static GetGpsCNavAlertFlagToSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert);
      static GetGpsCNavAlertFlagToSVResultPtr dynamicCast(CommandBasePtr ptr);
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

