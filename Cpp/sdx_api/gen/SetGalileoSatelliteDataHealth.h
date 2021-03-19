#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GalileoSatelliteDataHealth is deprecated since 21.3. You may use GalileoDataHealthForSV.
    /// 
    /// Set Galileo data health for I/NAV and F/NAV message
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    /// Health    bool   False means Navigation data valid; True means Working without guarantee
    ///

    class SetGalileoSatelliteDataHealth;
    typedef std::shared_ptr<SetGalileoSatelliteDataHealth> SetGalileoSatelliteDataHealthPtr;
    
    
    class SetGalileoSatelliteDataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoSatelliteDataHealth();

      SetGalileoSatelliteDataHealth(int prn, const std::string& component, bool health);
  
      static SetGalileoSatelliteDataHealthPtr create(int prn, const std::string& component, bool health);
      static SetGalileoSatelliteDataHealthPtr dynamicCast(CommandBasePtr ptr);
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
      bool health() const;
      void setHealth(bool health);
    };
  }
}

