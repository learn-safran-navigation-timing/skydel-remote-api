#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSatellitePower is deprecated since 21.3. You may use GetPowerForSV.
    /// 
    /// Get power offset for specified satellite PRN.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class GetSatellitePower;
    typedef std::shared_ptr<GetSatellitePower> GetSatellitePowerPtr;
    
    
    class GetSatellitePower : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePower();

      GetSatellitePower(const std::string& system, int prn);
  
      static GetSatellitePowerPtr create(const std::string& system, int prn);
      static GetSatellitePowerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

