#pragma once

#include <memory>
#include "command_base.h"

#include "gen/GNSSBand.h"
#include <optional>
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
    /// Band        GNSSBand        Offset will be apply to this band.
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetVehicleGainPatternOffset;
    typedef std::shared_ptr<GetVehicleGainPatternOffset> GetVehicleGainPatternOffsetPtr;
    
    
    class GetVehicleGainPatternOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleGainPatternOffset();

      GetVehicleGainPatternOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName = {});

      static GetVehicleGainPatternOffsetPtr create(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName = {});
      static GetVehicleGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** antennaName ****
      std::optional<std::string> antennaName() const;
      void setAntennaName(const std::optional<std::string>& antennaName);
    };
    
  }
}

