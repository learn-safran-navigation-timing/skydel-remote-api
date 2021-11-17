#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGalileoSatelliteSignalHealth is deprecated since 21.3. You may use SetGalileoSignalHealthForSV.
    /// 
    /// Set Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    /// Health    int    Signal health 0..3
    ///

    class SetGalileoSatelliteSignalHealth;
    typedef std::shared_ptr<SetGalileoSatelliteSignalHealth> SetGalileoSatelliteSignalHealthPtr;
    
    
    class SetGalileoSatelliteSignalHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoSatelliteSignalHealth();

      SetGalileoSatelliteSignalHealth(int prn, const std::string& component, int health);
  
      static SetGalileoSatelliteSignalHealthPtr create(int prn, const std::string& component, int health);
      static SetGalileoSatelliteSignalHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

