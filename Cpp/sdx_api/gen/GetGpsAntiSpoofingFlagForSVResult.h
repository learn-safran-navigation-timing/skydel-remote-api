#pragma once

#include <memory>
#include "command_result.h"
#include "gen/GpsASFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsAntiSpoofingFlagForSV
    ///
    /// Name         Type      Description
    /// ------------ --------- -----------------------
    /// SvId         int       Satellite's SV ID 1..32
    /// AntiSpoofing GpsASFlag GPS Anti-Spoofing Flag.
    ///

    class GetGpsAntiSpoofingFlagForSVResult;
    typedef std::shared_ptr<GetGpsAntiSpoofingFlagForSVResult> GetGpsAntiSpoofingFlagForSVResultPtr;
    
    
    class GetGpsAntiSpoofingFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsAntiSpoofingFlagForSVResult();

      GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing);
  
      static GetGpsAntiSpoofingFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing);
      static GetGpsAntiSpoofingFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);
    };
  }
}

