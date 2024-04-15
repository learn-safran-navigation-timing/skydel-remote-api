#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export the SBAS message sequence into a csv file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------------------------------------------------------
    /// Path        string The full path to the csv file.
    /// Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.
    ///

    class ExportSbasMessageSequence;
    typedef std::shared_ptr<ExportSbasMessageSequence> ExportSbasMessageSequencePtr;
    
    
    class ExportSbasMessageSequence : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ExportSbasMessageSequence();

      ExportSbasMessageSequence(const std::string& path, bool overwriting);

      static ExportSbasMessageSequencePtr create(const std::string& path, bool overwriting);
      static ExportSbasMessageSequencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

