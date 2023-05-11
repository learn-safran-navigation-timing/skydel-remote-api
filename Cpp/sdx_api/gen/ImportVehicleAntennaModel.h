#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import a vehicle antenna model from a XML file.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------
    /// FilePath string File path of the antenna model
    ///

    class ImportVehicleAntennaModel;
    typedef std::shared_ptr<ImportVehicleAntennaModel> ImportVehicleAntennaModelPtr;
    
    
    class ImportVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportVehicleAntennaModel();

      ImportVehicleAntennaModel(const std::string& filePath);

      static ImportVehicleAntennaModelPtr create(const std::string& filePath);
      static ImportVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);
    };
    
  }
}

