#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export a vehicle antenna model in a XML file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------------
    /// AntennaName string Vehicle antenna model name
    /// FilePath    string The antenna model will be exported in this file path.
    /// Overwriting bool   Overwrite the old file if true.
    ///

    class ExportVehicleAntennaModel;
    typedef std::shared_ptr<ExportVehicleAntennaModel> ExportVehicleAntennaModelPtr;
    
    
    class ExportVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportVehicleAntennaModel();

      ExportVehicleAntennaModel(const std::string& antennaName, const std::string& filePath, bool overwriting);

      static ExportVehicleAntennaModelPtr create(const std::string& antennaName, const std::string& filePath, bool overwriting);
      static ExportVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** antennaName ****
      std::string antennaName() const;
      void setAntennaName(const std::string& antennaName);


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);
    };
    
  }
}

