#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoSatelliteDataHealth is deprecated since 21.3. You may use GetGalileoDataHealthForSV.
    /// 
    /// Get Galileo data health for I/NAV and F/NAV message
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    ///

    class GetGalileoSatelliteDataHealth;
    typedef std::shared_ptr<GetGalileoSatelliteDataHealth> GetGalileoSatelliteDataHealthPtr;
    
    
    class GetGalileoSatelliteDataHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoSatelliteDataHealth();

      GetGalileoSatelliteDataHealth(int prn, const std::string& component);
  
      static GetGalileoSatelliteDataHealthPtr create(int prn, const std::string& component);
      static GetGalileoSatelliteDataHealthPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);
    };
  }
}

