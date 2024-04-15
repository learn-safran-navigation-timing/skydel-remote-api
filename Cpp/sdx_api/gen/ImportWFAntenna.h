#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import Wavefront Antenna settings from an XML file.
    ///
    /// Name     Type   Description
    /// -------- ------ -----------------------------------------
    /// FilePath string File path for Wavefront Antenna settings.
    ///

    class ImportWFAntenna;
    typedef std::shared_ptr<ImportWFAntenna> ImportWFAntennaPtr;
    
    
    class ImportWFAntenna : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ImportWFAntenna();

      ImportWFAntenna(const std::string& filePath);

      static ImportWFAntennaPtr create(const std::string& filePath);
      static ImportWFAntennaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** filePath ****
      std::string filePath() const;
      void setFilePath(const std::string& filePath);
    };
    
  }
}

