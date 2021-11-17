#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteL1cHealth is deprecated since 21.3. You may use SetGpsL1cHealthForSV.
    /// 
    /// Set GPS L1C health (used in CNAV2 only)
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health bool L1C health, false = signal OK, true = signal bad or unavailable
    ///

    class SetGpsSatelliteL1cHealth;
    typedef std::shared_ptr<SetGpsSatelliteL1cHealth> SetGpsSatelliteL1cHealthPtr;
    
    
    class SetGpsSatelliteL1cHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteL1cHealth();

      SetGpsSatelliteL1cHealth(int prn, bool health);
  
      static SetGpsSatelliteL1cHealthPtr create(int prn, bool health);
      static SetGpsSatelliteL1cHealthPtr dynamicCast(CommandBasePtr ptr);
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

