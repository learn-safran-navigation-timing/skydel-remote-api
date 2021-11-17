#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoSatelliteSignalHealth is deprecated since 21.3. You may use GetGalileoSignalHealthForSV.
    /// 
    /// Get Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name      Type   Description
    /// --------- ------ ------------------------------------------
    /// Prn       int    Satellite PRN number 1..36
    /// Component string Component is either "E5a", "E5b", or "E1B"
    ///

    class GetGalileoSatelliteSignalHealth;
    typedef std::shared_ptr<GetGalileoSatelliteSignalHealth> GetGalileoSatelliteSignalHealthPtr;
    
    
    class GetGalileoSatelliteSignalHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoSatelliteSignalHealth();

      GetGalileoSatelliteSignalHealth(int prn, const std::string& component);
  
      static GetGalileoSatelliteSignalHealthPtr create(int prn, const std::string& component);
      static GetGalileoSatelliteSignalHealthPtr dynamicCast(CommandBasePtr ptr);
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

