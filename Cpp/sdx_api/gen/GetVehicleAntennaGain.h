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


      GetVehicleAntennaGain();

      GetVehicleAntennaGain(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static GetVehicleAntennaGainPtr create(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});
      static GetVehicleAntennaGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

