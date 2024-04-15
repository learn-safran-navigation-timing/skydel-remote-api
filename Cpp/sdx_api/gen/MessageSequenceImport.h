#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import a sequence file.
    /// A sequence file is a CSV with one message type per line.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------------------------
    /// Signal   string Signal Name ("L2C" for example)
    /// Filename string Path to the CSV file on the simulator's machine.
    ///

    class MessageSequenceImport;
    typedef std::shared_ptr<MessageSequenceImport> MessageSequenceImportPtr;
    
    
    class MessageSequenceImport : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      MessageSequenceImport();

      MessageSequenceImport(const std::string& signal, const std::string& filename);

      static MessageSequenceImportPtr create(const std::string& signal, const std::string& filename);
      static MessageSequenceImportPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** filename ****
      std::string filename() const;
      void setFilename(const std::string& filename);
    };
    
  }
}

