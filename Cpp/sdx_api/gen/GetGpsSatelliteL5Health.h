#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteL5Health is deprecated since 21.3. You may use GpsL5HealthForSV.
    /// 
    /// Get GPS L5 health (used with CNAV and CNAV2)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteL5Health;
    typedef std::shared_ptr<GetGpsSatelliteL5Health> GetGpsSatelliteL5HealthPtr;
    
    
    class GetGpsSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL5Health();

      GetGpsSatelliteL5Health(int prn);
  
      static GetGpsSatelliteL5HealthPtr create(int prn);
      static GetGpsSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

