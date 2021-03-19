#pragma once

#include <memory>
#include "command_base.h"
#include "gen/GpsASFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS Anti-Spoofing Flag
    ///
    /// Name         Type      Description
    /// ------------ --------- -----------------------
    /// SvId         int       Satellite's SV ID 1..32
    /// AntiSpoofing GpsASFlag GPS Anti-Spoofing Flag.
    ///

    class SetGpsAntiSpoofingFlagForSV;
    typedef std::shared_ptr<SetGpsAntiSpoofingFlagForSV> SetGpsAntiSpoofingFlagForSVPtr;
    
    
    class SetGpsAntiSpoofingFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsAntiSpoofingFlagForSV();

      SetGpsAntiSpoofingFlagForSV(int svId, const Sdx::GpsASFlag& antiSpoofing);
  
      static SetGpsAntiSpoofingFlagForSVPtr create(int svId, const Sdx::GpsASFlag& antiSpoofing);
      static SetGpsAntiSpoofingFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antiSpoofing ****
      Sdx::GpsASFlag antiSpoofing() const;
      void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing);
    };
  }
}

