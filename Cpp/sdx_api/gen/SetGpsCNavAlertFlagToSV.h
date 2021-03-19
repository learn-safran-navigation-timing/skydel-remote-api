#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS CNAV Alert Flag
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------------------------
    /// SvId  int  Satellite's SV ID 1..32
    /// Alert bool GPS CNAV Alert Flag, false = No Alert, true = Alert
    ///

    class SetGpsCNavAlertFlagToSV;
    typedef std::shared_ptr<SetGpsCNavAlertFlagToSV> SetGpsCNavAlertFlagToSVPtr;
    
    
    class SetGpsCNavAlertFlagToSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsCNavAlertFlagToSV();

      SetGpsCNavAlertFlagToSV(int svId, bool alert);
  
      static SetGpsCNavAlertFlagToSVPtr create(int svId, bool alert);
      static SetGpsCNavAlertFlagToSVPtr dynamicCast(CommandBasePtr ptr);
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

