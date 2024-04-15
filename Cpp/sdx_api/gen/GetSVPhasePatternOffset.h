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
    /// Get the offset (in rad) for the antenna phase pattern of the band.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2" or "L5")
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetSVPhasePatternOffset;
    typedef std::shared_ptr<GetSVPhasePatternOffset> GetSVPhasePatternOffsetPtr;
    
    
    class GetSVPhasePatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVPhasePatternOffset();

      GetSVPhasePatternOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName = {});

      static GetSVPhasePatternOffsetPtr create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName = {});
      static GetSVPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

