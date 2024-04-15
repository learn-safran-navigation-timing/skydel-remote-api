#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export Wavefront Antenna settings to an XML file.
    ///
    /// Name          Type   Description
    /// ------------- ------ -------------------------------------------------
    /// FilePath      string Export file path for Wavefront Antenna settings.
    /// OverwriteFile bool   When selected, existing file will be overwritten.
    ///

    class ExportWFAntenna;
    typedef std::shared_ptr<ExportWFAntenna> ExportWFAntennaPtr;
    
    
    class ExportWFAntenna : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportWFAntenna();

      ExportWFAntenna(const std::string& filePath, bool overwriteFile);

      static ExportWFAntennaPtr create(const std::string& filePath, bool overwriteFile);
      static ExportWFAntennaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);


      // **** overwriteFile ****
      bool overwriteFile() const;
      void setOverwriteFile(bool overwriteFile);
    };
    
  }
}

