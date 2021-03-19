#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteL2Health is deprecated since 21.3. You may use GpsL2HealthForSV.
    /// 
    /// Get GPS L2 health (used with CNAV and CNAV2)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteL2Health;
    typedef std::shared_ptr<GetGpsSatelliteL2Health> GetGpsSatelliteL2HealthPtr;
    
    
    class GetGpsSatelliteL2Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL2Health();

      GetGpsSatelliteL2Health(int prn);
  
      static GetGpsSatelliteL2HealthPtr create(int prn);
      static GetGpsSatelliteL2HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

