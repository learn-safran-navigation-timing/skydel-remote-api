#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVGainPatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Offset      double          Power offset
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetSVGainPatternOffsetResult;
    typedef std::shared_ptr<GetSVGainPatternOffsetResult> GetSVGainPatternOffsetResultPtr;
    
    
    class GetSVGainPatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVGainPatternOffsetResult();

      GetSVGainPatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      GetSVGainPatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      static GetSVGainPatternOffsetResultPtr create(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      static GetSVGainPatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});
      static GetSVGainPatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
      std::optional<std::string> antennaName() const;
      void setAntennaName(const std::optional<std::string>& antennaName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVGainPatternOffsetResult);
  }
}

