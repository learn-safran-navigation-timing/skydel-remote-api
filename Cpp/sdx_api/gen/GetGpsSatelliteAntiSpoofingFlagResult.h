#pragma once

#include <memory>
#include "command_result.h"
#include "gen/GpsASFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteAntiSpoofingFlag.
    ///
    /// Name         Type      Description
    /// ------------ --------- --------------------------
    /// Prn          int       Satellite PRN number 1..32
    /// AntiSpoofing GpsASFlag GPS Anti-Spoofing Flag.
    ///

    class GetGpsSatelliteAntiSpoofingFlagResult;
    typedef std::shared_ptr<GetGpsSatelliteAntiSpoofingFlagResult> GetGpsSatelliteAntiSpoofingFlagResultPtr;
    
    
    class GetGpsSatelliteAntiSpoofingFlagResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteAntiSpoofingFlagResult();

      GetGpsSatelliteAntiSpoofingFlagResult(CommandBasePtr relatedCommand, int prn, const Sdx::GpsASFlag& antiSpoofing);
  
      static GetGpsSatelliteAntiSpoofingFlagResultPtr create(CommandBasePtr relatedCommand, int prn, const Sdx::GpsASFlag& antiSpoofing);
      static GetGpsSatelliteAntiSpoofingFlagResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);
    };
  }
}

