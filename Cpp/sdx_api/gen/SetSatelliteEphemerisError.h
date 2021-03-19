#pragma once

#include <memory>
#include "command_base.h"
#include <string>
#include "gen/RIC.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SatelliteEphemerisError is deprecated since 21.3. You may use EphemerisErrorForSV.
    /// 
    /// Set the satellite ephemeris error.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS" or "NavIC"
    /// Prn      int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.
    /// DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.
    /// DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.
    ///

    class SetSatelliteEphemerisError;
    typedef std::shared_ptr<SetSatelliteEphemerisError> SetSatelliteEphemerisErrorPtr;
    
    
    class SetSatelliteEphemerisError : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSatelliteEphemerisError();

      SetSatelliteEphemerisError(const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);
  
      static SetSatelliteEphemerisErrorPtr create(const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);
      static SetSatelliteEphemerisErrorPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** orbit ****
      Sdx::RIC orbit() const;
      void setOrbit(const Sdx::RIC& orbit);


      // **** deltaAf0 ****
      double deltaAf0() const;
      void setDeltaAf0(double deltaAf0);


      // **** deltaAf1 ****
      double deltaAf1() const;
      void setDeltaAf1(double deltaAf1);
    };
  }
}

