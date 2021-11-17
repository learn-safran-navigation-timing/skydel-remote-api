#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsSatelliteDataHealth is deprecated since 21.3. You may use SetGpsDataHealthForSV.
    /// 
    /// Set GPS nav data health
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health int  Data health 0..7
    ///

    class SetGpsSatelliteDataHealth;
    typedef std::shared_ptr<SetGpsSatelliteDataHealth> SetGpsSatelliteDataHealthPtr;
    
    
    class SetGpsSatelliteDataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteDataHealth();

      SetGpsSatelliteDataHealth(int prn, int health);
  
      static SetGpsSatelliteDataHealthPtr create(int prn, int health);
      static SetGpsSatelliteDataHealthPtr dynamicCast(CommandBasePtr ptr);
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

