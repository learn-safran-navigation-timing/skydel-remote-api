#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SatelliteEphemerisError is deprecated since 21.3. You may use EphemerisErrorForSV.
    /// 
    /// Get the satellite ephemeris error.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class GetSatelliteEphemerisError;
    typedef std::shared_ptr<GetSatelliteEphemerisError> GetSatelliteEphemerisErrorPtr;
    
    
    class GetSatelliteEphemerisError : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatelliteEphemerisError();

      GetSatelliteEphemerisError(const std::string& system, int prn);
  
      static GetSatelliteEphemerisErrorPtr create(const std::string& system, int prn);
      static GetSatelliteEphemerisErrorPtr dynamicCast(CommandBasePtr ptr);
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

