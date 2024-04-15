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
    /// Add an offset (in dB) for all values of the pattern.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2" or "L5")
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Offset      double          Power offset
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class AddSVGainPatternOffset;
    typedef std::shared_ptr<AddSVGainPatternOffset> AddSVGainPatternOffsetPtr;
    
    
    class AddSVGainPatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      AddSVGainPatternOffset();

      AddSVGainPatternOffset(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName = {});

      static AddSVGainPatternOffsetPtr create(const Sdx::GNSSBand& band, const std::string& system, double offset, const Sdx::optional<std::string>& antennaName = {});
      static AddSVGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr);
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


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** antennaName ****
      Sdx::optional<std::string> antennaName() const;
      void setAntennaName(const Sdx::optional<std::string>& antennaName);
    };
    
  }
}

