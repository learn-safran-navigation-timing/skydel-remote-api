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
    /// Get space vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
    ///
    /// Name   Type            Description
    /// ------ --------------- --------------------------------------------------------------------------
    /// Band   GNSSBand        Frequency band
    /// System string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Name   optional string SV antenna name
    ///

    class GetSVAntennaPhaseOffset;
    typedef std::shared_ptr<GetSVAntennaPhaseOffset> GetSVAntennaPhaseOffsetPtr;
    
    
    class GetSVAntennaPhaseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVAntennaPhaseOffset();

      GetSVAntennaPhaseOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});

      static GetSVAntennaPhaseOffsetPtr create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name = {});
      static GetSVAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr);
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


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

