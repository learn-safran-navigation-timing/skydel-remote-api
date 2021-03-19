#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS NAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// SvId  int  Satellite SV ID 1..10
    /// Alert bool QZSS NAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetQzssNavAlertFlagForSV;
    typedef std::shared_ptr<SetQzssNavAlertFlagForSV> SetQzssNavAlertFlagForSVPtr;
    
    
    class SetQzssNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssNavAlertFlagForSV();

      SetQzssNavAlertFlagForSV(int svId, bool alert);
  
      static SetQzssNavAlertFlagForSVPtr create(int svId, bool alert);
      static SetQzssNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
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

