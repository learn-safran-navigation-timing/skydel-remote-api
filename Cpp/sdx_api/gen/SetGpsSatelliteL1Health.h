#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteL1Health is deprecated since 21.3. You may use SetGpsL1HealthForSV.
    /// 
    /// Set GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L1 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsSatelliteL1Health;
    typedef std::shared_ptr<SetGpsSatelliteL1Health> SetGpsSatelliteL1HealthPtr;
    
    
    class SetGpsSatelliteL1Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteL1Health();

      SetGpsSatelliteL1Health(int prn, bool health);
  
      static SetGpsSatelliteL1HealthPtr create(int prn, bool health);
      static SetGpsSatelliteL1HealthPtr dynamicCast(CommandBasePtr ptr);
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

