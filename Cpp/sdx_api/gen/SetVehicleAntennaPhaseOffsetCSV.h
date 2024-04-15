#pragma once

#include <memory>
#include "command_base.h"

#include "gen/AntennaPatternFileType.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle phase offset antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.
    ///
    /// Name       Type                   Description
    /// ---------- ---------------------- ------------------------------------------------------------------------------------------------------------------
    /// FilePath   string                 File path of the CSV. For Default and None type, lets it empty. See formats in user manual part 8.7.9.2.1. Models.
    /// FileFormat AntennaPatternFileType Values' unit of the CSV File: "Degrees", "Radians" or "NoneFile" in case of None-pattern type.
    /// Type       AntennaPatternType     Pattern type
    /// Band       GNSSBand               Frequency band
    /// Name       optional string        Vehicle antenna name
    ///

    class SetVehicleAntennaPhaseOffsetCSV;
    typedef std::shared_ptr<SetVehicleAntennaPhaseOffsetCSV> SetVehicleAntennaPhaseOffsetCSVPtr;
    
    
    class SetVehicleAntennaPhaseOffsetCSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetVehicleAntennaPhaseOffsetCSV();

      SetVehicleAntennaPhaseOffsetCSV(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});

      static SetVehicleAntennaPhaseOffsetCSVPtr create(const std::string& filePath, const Sdx::AntennaPatternFileType& fileFormat, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name = {});
      static SetVehicleAntennaPhaseOffsetCSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** fileFormat ****
      Sdx::AntennaPatternFileType fileFormat() const;
      void setFileFormat(const Sdx::AntennaPatternFileType& fileFormat);


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

