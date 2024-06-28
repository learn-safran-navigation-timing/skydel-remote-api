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
    /// Result of GetSVPhasePatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2", "L5", "E6" or "S")
    /// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Offset      double          Phase offset (in rad)
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetSVPhasePatternOffsetResult;
    typedef std::shared_ptr<GetSVPhasePatternOffsetResult> GetSVPhasePatternOffsetResultPtr;
    
    
    class GetSVPhasePatternOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVPhasePatternOffsetResult();

      GetSVPhasePatternOffsetResult(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      GetSVPhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      static GetSVPhasePatternOffsetResultPtr create(const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});

      static GetSVPhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, const std::string& system, double offset, const std::optional<std::string>& antennaName = {});
      static GetSVPhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVPhasePatternOffsetResult);
  }
}

