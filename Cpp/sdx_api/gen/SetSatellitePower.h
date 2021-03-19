#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSatellitePower is deprecated since 21.3. You may use SetPowerForSV.
    /// 
    /// Set power offset for specified satellite PRN. Use PRN 0 to set power for all satellites.
    ///
    /// Name            Type   Description
    /// --------------- ------ ----------------------------------------------------------------------------------------------------------
    /// System          string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn             int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// PowerOffset     double Power offset in dB (relative to signal power reference level)
    /// OtherSatsFollow bool   If true, other sats power will be adjusted to maintain current offsets between satellites
    ///

    class SetSatellitePower;
    typedef std::shared_ptr<SetSatellitePower> SetSatellitePowerPtr;
    
    
    class SetSatellitePower : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSatellitePower();

      SetSatellitePower(const std::string& system, int prn, double powerOffset, bool otherSatsFollow);
  
      static SetSatellitePowerPtr create(const std::string& system, int prn, double powerOffset, bool otherSatsFollow);
      static SetSatellitePowerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** powerOffset ****
      double powerOffset() const;
      void setPowerOffset(double powerOffset);


      // **** otherSatsFollow ****
      bool otherSatsFollow() const;
      void setOtherSatsFollow(bool otherSatsFollow);
    };
  }
}

