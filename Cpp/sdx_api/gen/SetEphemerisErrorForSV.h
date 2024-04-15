#pragma once

#include <memory>
#include "command_base.h"

#include "gen/RIC.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite ephemeris error.
    ///
    /// Name     Type   Description
    /// -------- ------ -----------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId     int    Satellite SV ID.
    /// Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.
    /// DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.
    /// DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.
    ///

    class SetEphemerisErrorForSV;
    typedef std::shared_ptr<SetEphemerisErrorForSV> SetEphemerisErrorForSVPtr;
    
    
    class SetEphemerisErrorForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetEphemerisErrorForSV();

      SetEphemerisErrorForSV(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);

      static SetEphemerisErrorForSVPtr create(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1);
      static SetEphemerisErrorForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


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

