#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteSignalHealth is deprecated since 21.3. You may use GpsSignalHealthForSV.
    /// 
    /// Set GPS signal health
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health int  Signal health 0..31
    ///

    class SetGpsSatelliteSignalHealth;
    typedef std::shared_ptr<SetGpsSatelliteSignalHealth> SetGpsSatelliteSignalHealthPtr;
    
    
    class SetGpsSatelliteSignalHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteSignalHealth();

      SetGpsSatelliteSignalHealth(int prn, int health);
  
      static SetGpsSatelliteSignalHealthPtr create(int prn, int health);
      static SetGpsSatelliteSignalHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

