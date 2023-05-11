#pragma once

#include <memory>
#include "command_base.h"

#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the offset (in dB) for the antenna gain pattern of the band.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2" or "L5")
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetSVGainPatternOffset;
    typedef std::shared_ptr<GetSVGainPatternOffset> GetSVGainPatternOffsetPtr;
    
    
    class GetSVGainPatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVGainPatternOffset();

      GetSVGainPatternOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName = {});

      static GetSVGainPatternOffsetPtr create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName = {});
      static GetSVGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** antennaName ****
      Sdx::optional<std::string> antennaName() const;
      void setAntennaName(const Sdx::optional<std::string>& antennaName);
    };
    
  }
}

