#pragma once

#include <memory>
#include "command_base.h"

#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.
    ///
    /// Name     Type               Description
    /// -------- ------------------ ----------------------------------------------------------------------------------------------------------------------
    /// FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty
    /// Type     AntennaPatternType Pattern type
    /// Band     GNSSBand           Frequency band
    /// Name     optional string    Vehicle antenna name
    ///

    class SetVehicleAntennaGainCSV;
    typedef std::shared_ptr<SetVehicleAntennaGainCSV> SetVehicleAntennaGainCSVPtr;
    
    
    class SetVehicleAntennaGainCSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetVehicleAntennaGainCSV();

      SetVehicleAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static SetVehicleAntennaGainCSVPtr create(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});
      static SetVehicleAntennaGainCSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** type ****
      Sdx::AntennaPatternType type() const;
      void setType(const Sdx::AntennaPatternType& type);


      // **** band ****
      Sdx::GNSSBand band() const;
      void setBand(const Sdx::GNSSBand& band);


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

