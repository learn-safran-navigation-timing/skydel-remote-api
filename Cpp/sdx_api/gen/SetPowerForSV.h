#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetPowerForSV is deprecated since 22.7. You may use SetManualPowerOffsetForSV.
    /// 
    /// Set power offset for specified satellite SV ID. Use SV ID 0 to set power for all satellites.
    ///
    /// Name            Type   Description
    /// --------------- ------ -----------------------------------------------------------------------------------------
    /// System          string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId            int    The Satellite SV ID
    /// PowerOffset     double Power offset in dB (relative to signal power reference level)
    /// OtherSatsFollow bool   If true, other sats power will be adjusted to maintain current offsets between satellites
    ///

    class SetPowerForSV;
    typedef std::shared_ptr<SetPowerForSV> SetPowerForSVPtr;
    
    
    class SetPowerForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      SetPowerForSV();

      SetPowerForSV(const std::string& system, int svId, double powerOffset, bool otherSatsFollow);

      static SetPowerForSVPtr create(const std::string& system, int svId, double powerOffset, bool otherSatsFollow);
      static SetPowerForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** powerOffset ****
      double powerOffset() const;
      void setPowerOffset(double powerOffset);


      // **** otherSatsFollow ****
      bool otherSatsFollow() const;
      void setOtherSatsFollow(bool otherSatsFollow);
    };
    
  }
}

