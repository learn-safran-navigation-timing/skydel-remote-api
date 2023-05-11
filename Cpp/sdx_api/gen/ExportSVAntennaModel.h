#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export a space vehicle antenna model in a XML file.
    ///
    /// Name        Type   Description
    /// ----------- ------ ----------------------------------------------------------------
    /// AntennaName string SV antenna model name
    /// System      string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// FilePath    string The antenna model will be exported in this file path.
    /// Overwriting bool   Overwrite the old file if true.
    ///

    class ExportSVAntennaModel;
    typedef std::shared_ptr<ExportSVAntennaModel> ExportSVAntennaModelPtr;
    
    
    class ExportSVAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ExportSVAntennaModel();

      ExportSVAntennaModel(const std::string& antennaName, const std::string& system, const std::string& filePath, bool overwriting);

      static ExportSVAntennaModelPtr create(const std::string& antennaName, const std::string& system, const std::string& filePath, bool overwriting);
      static ExportSVAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** antennaName ****
      std::string antennaName() const;
      void setAntennaName(const std::string& antennaName);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);
    };
    
  }
}

