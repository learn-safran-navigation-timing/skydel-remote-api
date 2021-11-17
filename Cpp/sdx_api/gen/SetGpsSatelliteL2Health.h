#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteL2Health is deprecated since 21.3. You may use SetGpsL2HealthForSV.
    /// 
    /// Set GPS L2 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L2 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsSatelliteL2Health;
    typedef std::shared_ptr<SetGpsSatelliteL2Health> SetGpsSatelliteL2HealthPtr;
    
    
    class SetGpsSatelliteL2Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteL2Health();

      SetGpsSatelliteL2Health(int prn, bool health);
  
      static SetGpsSatelliteL2HealthPtr create(int prn, bool health);
      static SetGpsSatelliteL2HealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

