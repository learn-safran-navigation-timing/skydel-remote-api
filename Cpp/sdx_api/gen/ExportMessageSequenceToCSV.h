#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export the signal's message sequence into a csv file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------------------------------
    /// Signal      string Signal key ("L2C" for example).
    /// Path        string The full path to the csv file.
    /// Overwriting bool   Overwrites an existing file if set to true, returns an error if set to false and the file exists.
    ///

    class ExportMessageSequenceToCSV;
    typedef std::shared_ptr<ExportMessageSequenceToCSV> ExportMessageSequenceToCSVPtr;
    
    
    class ExportMessageSequenceToCSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportMessageSequenceToCSV();

      ExportMessageSequenceToCSV(const std::string& signal, const std::string& path, bool overwriting);

      static ExportMessageSequenceToCSVPtr create(const std::string& signal, const std::string& path, bool overwriting);
      static ExportMessageSequenceToCSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** overwriting ****
      bool overwriting() const;
      void setOverwriting(bool overwriting);
    };
    
  }
}

