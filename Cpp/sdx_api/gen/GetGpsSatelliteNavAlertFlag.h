#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteNavAlertFlag is deprecated since 21.3. You may use GpsNavAlertFlagForSV.
    /// 
    /// Get GPS NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteNavAlertFlag;
    typedef std::shared_ptr<GetGpsSatelliteNavAlertFlag> GetGpsSatelliteNavAlertFlagPtr;
    
    
    class GetGpsSatelliteNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteNavAlertFlag();

      GetGpsSatelliteNavAlertFlag(int prn);
  
      static GetGpsSatelliteNavAlertFlagPtr create(int prn);
      static GetGpsSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

