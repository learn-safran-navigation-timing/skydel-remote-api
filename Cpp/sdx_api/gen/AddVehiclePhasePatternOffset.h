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
    /// Add an offset (in rad) for all values of the phase pattern.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band. ("L1", "L2" or "L5")
    /// Offset      double          Phase offset (in rad)
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class AddVehiclePhasePatternOffset;
    typedef std::shared_ptr<AddVehiclePhasePatternOffset> AddVehiclePhasePatternOffsetPtr;
    
    
    class AddVehiclePhasePatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      AddVehiclePhasePatternOffset();

      AddVehiclePhasePatternOffset(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});

      static AddVehiclePhasePatternOffsetPtr create(const Sdx::GNSSBand& band, double offset, const Sdx::optional<std::string>& antennaName = {});
      static AddVehiclePhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);


      // **** antennaName ****
      Sdx::optional<std::string> antennaName() const;
      void setAntennaName(const Sdx::optional<std::string>& antennaName);
    };
    
  }
}

