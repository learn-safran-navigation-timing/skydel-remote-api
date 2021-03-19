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
    /// Get the satellite pseudorange noise constant offset.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class GetSatellitePseudorangeNoiseOffset;
    typedef std::shared_ptr<GetSatellitePseudorangeNoiseOffset> GetSatellitePseudorangeNoiseOffsetPtr;
    
    
    class GetSatellitePseudorangeNoiseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSatellitePseudorangeNoiseOffset();

      GetSatellitePseudorangeNoiseOffset(const std::string& system, int prn);
  
      static GetSatellitePseudorangeNoiseOffsetPtr create(const std::string& system, int prn);
      static GetSatellitePseudorangeNoiseOffsetPtr dynamicCast(CommandBasePtr ptr);
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

