#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use GetNavICNavAlertFlagForSV.
    /// 
    /// Get NavIC NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..14
    ///

    class GetNavICSatelliteNavAlertFlag;
    typedef std::shared_ptr<GetNavICSatelliteNavAlertFlag> GetNavICSatelliteNavAlertFlagPtr;
    
    
    class GetNavICSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICSatelliteNavAlertFlag();

      GetNavICSatelliteNavAlertFlag(int svId);
  
      static GetNavICSatelliteNavAlertFlagPtr create(int svId);
      static GetNavICSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

