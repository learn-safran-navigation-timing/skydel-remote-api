#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get streaming buffer size.
    ///
    /// 
    ///

    class GetStreamingBuffer;
    typedef std::shared_ptr<GetStreamingBuffer> GetStreamingBufferPtr;
    
    
    class GetStreamingBuffer : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStreamingBuffer();

      static GetStreamingBufferPtr create();
      static GetStreamingBufferPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

