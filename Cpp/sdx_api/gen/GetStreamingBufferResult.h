#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStreamingBuffer.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------
    /// Size int  Streaming buffer size in msec
    ///

    class GetStreamingBufferResult;
    typedef std::shared_ptr<GetStreamingBufferResult> GetStreamingBufferResultPtr;
    
    
    class GetStreamingBufferResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStreamingBufferResult();

      GetStreamingBufferResult(int size);

      GetStreamingBufferResult(CommandBasePtr relatedCommand, int size);

      static GetStreamingBufferResultPtr create(int size);

      static GetStreamingBufferResultPtr create(CommandBasePtr relatedCommand, int size);
      static GetStreamingBufferResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** size ****
      int size() const;
      void setSize(int size);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetStreamingBufferResult);
  }
}

