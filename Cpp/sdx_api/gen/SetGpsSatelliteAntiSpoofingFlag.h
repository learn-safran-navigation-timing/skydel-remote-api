#pragma once

#include <memory>
#include "command_base.h"
#include "gen/GpsASFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteAntiSpoofingFlag is deprecated since 21.3. You may use GpsAntiSpoofingFlagForSV.
    /// 
    /// Set GPS Anti-Spoofing Flag
    ///
    /// Name         Type      Description
    /// ------------ --------- --------------------------
    /// Prn          int       Satellite PRN number 1..32
    /// AntiSpoofing GpsASFlag GPS Anti-Spoofing Flag.
    ///

    class SetGpsSatelliteAntiSpoofingFlag;
    typedef std::shared_ptr<SetGpsSatelliteAntiSpoofingFlag> SetGpsSatelliteAntiSpoofingFlagPtr;
    
    
    class SetGpsSatelliteAntiSpoofingFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSatelliteAntiSpoofingFlag();

      SetGpsSatelliteAntiSpoofingFlag(int prn, const Sdx::GpsASFlag& antiSpoofing);
  
      static SetGpsSatelliteAntiSpoofingFlagPtr create(int prn, const Sdx::GpsASFlag& antiSpoofing);
      static SetGpsSatelliteAntiSpoofingFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);
    };
  }
}

