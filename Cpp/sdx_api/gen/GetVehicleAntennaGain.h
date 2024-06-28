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
    /// Get Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.
    ///
    /// Name Type            Description
    /// ---- --------------- --------------------
    /// Band GNSSBand        Frequency band
    /// Name optional string Vehicle antenna name
    ///

    class GetVehicleAntennaGain;
    typedef std::shared_ptr<GetVehicleAntennaGain> GetVehicleAntennaGainPtr;
    
    
    class GetVehicleAntennaGain : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleAntennaGain();

      GetVehicleAntennaGain(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});

      static GetVehicleAntennaGainPtr create(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {});
      static GetVehicleAntennaGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      std::optional<std::string> name() const;
      void setName(const std::optional<std::string>& name);
    };
    
  }
}

