#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMessageSequence.
    ///
    /// Name     Type      Description
    /// -------- --------- -------------------------------
    /// Signal   string    Signal Name ("L2C" for example)
    /// Sequence array int List of message type
    ///

    class GetMessageSequenceResult;
    typedef std::shared_ptr<GetMessageSequenceResult> GetMessageSequenceResultPtr;
    
    
    class GetMessageSequenceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageSequenceResult();

      GetMessageSequenceResult(const std::string& signal, const std::vector<int>& sequence);

      GetMessageSequenceResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence);

      static GetMessageSequenceResultPtr create(const std::string& signal, const std::vector<int>& sequence);

      static GetMessageSequenceResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence);
      static GetMessageSequenceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** sequence ****
      std::vector<int> sequence() const;
      void setSequence(const std::vector<int>& sequence);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageSequenceResult);
  }
}

