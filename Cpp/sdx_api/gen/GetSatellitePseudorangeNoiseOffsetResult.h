#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSatellitePseudorangeNoiseOffset.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class GetSatellitePseudorangeNoiseOffsetResult;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseOffsetResult> GetSatellitePseudorangeNoiseOffsetResultPtr;
    
    
    class GetSatellitePseudorangeNoiseOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseOffsetResult();

      GetSatellitePseudorangeNoiseOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled, double offset);
  
      static GetSatellitePseudorangeNoiseOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool enabled, double offset);
      static GetSatellitePseudorangeNoiseOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
  }
}

