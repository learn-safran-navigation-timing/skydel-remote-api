#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SatellitePseudorangeNoiseOffset is deprecated since 21.3. You may use PseudorangeNoiseOffsetForSV.
    /// 
    /// Set the satellite pseudorange noise constant offset.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn     int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class SetSatellitePseudorangeNoiseOffset;
    typedef std::shared_ptr<SetSatellitePseudorangeNoiseOffset> SetSatellitePseudorangeNoiseOffsetPtr;
    
    
    class SetSatellitePseudorangeNoiseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSatellitePseudorangeNoiseOffset();

      SetSatellitePseudorangeNoiseOffset(const std::string& system, int prn, bool enabled, double offset);
  
      static SetSatellitePseudorangeNoiseOffsetPtr create(const std::string& system, int prn, bool enabled, double offset);
      static SetSatellitePseudorangeNoiseOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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

