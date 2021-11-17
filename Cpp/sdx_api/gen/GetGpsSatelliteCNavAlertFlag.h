#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSatelliteCNavAlertFlag is deprecated since 21.3. You may use GetGpsCNavAlertFlagToSV.
    /// 
    /// Get GPS CNAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteCNavAlertFlag;
    typedef std::shared_ptr<GetGpsSatelliteCNavAlertFlag> GetGpsSatelliteCNavAlertFlagPtr;
    
    
    class GetGpsSatelliteCNavAlertFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteCNavAlertFlag();

      GetGpsSatelliteCNavAlertFlag(int prn);
  
      static GetGpsSatelliteCNavAlertFlagPtr create(int prn);
      static GetGpsSatelliteCNavAlertFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

