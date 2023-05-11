#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import a space vehicle antenna model from a XML file.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------------
    /// FilePath string File path of the antenna model
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class ImportSVAntennaModel;
    typedef std::shared_ptr<ImportSVAntennaModel> ImportSVAntennaModelPtr;
    
    
    class ImportSVAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportSVAntennaModel();

      ImportSVAntennaModel(const std::string& filePath, const std::string& system);

      static ImportSVAntennaModelPtr create(const std::string& filePath, const std::string& system);
      static ImportSVAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

