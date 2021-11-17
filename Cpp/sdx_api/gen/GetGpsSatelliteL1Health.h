#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSatelliteL1Health is deprecated since 21.3. You may use GetGpsL1HealthForSV.
    /// 
    /// Get GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteL1Health;
    typedef std::shared_ptr<GetGpsSatelliteL1Health> GetGpsSatelliteL1HealthPtr;
    
    
    class GetGpsSatelliteL1Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteL1Health();

      GetGpsSatelliteL1Health(int prn);
  
      static GetGpsSatelliteL1HealthPtr create(int prn);
      static GetGpsSatelliteL1HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

