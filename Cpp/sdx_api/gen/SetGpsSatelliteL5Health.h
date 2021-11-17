#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteL5Health is deprecated since 21.3. You may use SetGpsL5HealthForSV.
    /// 
    /// Set GPS L5 health (used with CNAV and CNAV2)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L5 health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsSatelliteL5Health;
    typedef std::shared_ptr<SetGpsSatelliteL5Health> SetGpsSatelliteL5HealthPtr;
    
    
    class SetGpsSatelliteL5Health : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteL5Health();

      SetGpsSatelliteL5Health(int prn, bool health);
  
      static SetGpsSatelliteL5HealthPtr create(int prn, bool health);
      static SetGpsSatelliteL5HealthPtr dynamicCast(CommandBasePtr ptr);
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

