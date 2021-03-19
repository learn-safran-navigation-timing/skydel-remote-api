#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsSatelliteAntiSpoofingFlag is deprecated since 21.3. You may use GpsAntiSpoofingFlagForSV.
    /// 
    /// Get GPS Anti-Spoofing Flag
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsSatelliteAntiSpoofingFlag;
    typedef std::shared_ptr<GetGpsSatelliteAntiSpoofingFlag> GetGpsSatelliteAntiSpoofingFlagPtr;
    
    
    class GetGpsSatelliteAntiSpoofingFlag : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteAntiSpoofingFlag();

      GetGpsSatelliteAntiSpoofingFlag(int prn);
  
      static GetGpsSatelliteAntiSpoofingFlagPtr create(int prn);
      static GetGpsSatelliteAntiSpoofingFlagPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

