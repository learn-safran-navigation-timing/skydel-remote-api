#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export the performance graph data into a csv file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------------------------------------------------------
    /// Path        string The full path to the csv file.
    /// Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.
    ///

    class ExportPerformanceDataToCSV;
    typedef std::shared_ptr<ExportPerformanceDataToCSV> ExportPerformanceDataToCSVPtr;
    
    
    class ExportPerformanceDataToCSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ExportPerformanceDataToCSV();

      ExportPerformanceDataToCSV(const std::string& path, bool overwriting);

      static ExportPerformanceDataToCSVPtr create(const std::string& path, bool overwriting);
      static ExportPerformanceDataToCSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);
    };
    
  }
}

