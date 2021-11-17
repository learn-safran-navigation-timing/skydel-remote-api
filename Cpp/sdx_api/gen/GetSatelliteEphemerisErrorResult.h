#pragma once

#include <memory>
#include "command_result.h"
#include "gen/RIC.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSatelliteEphemerisError.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS" or "NavIC"
    /// Prn      int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.
    /// DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.
    /// DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.
    ///

    class GetSatelliteEphemerisErrorResult;
    typedef std::shared_ptr<GetSatelliteEphemerisErrorResult> GetSatelliteEphemerisErrorResultPtr;
    
    
    class GetSatelliteEphemerisErrorResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatelliteEphemerisErrorResult();

      GetSatelliteEphemerisErrorResult(CommandBasePtr relatedCommand, const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);
  
      static GetSatelliteEphemerisErrorResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);
      static GetSatelliteEphemerisErrorResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

