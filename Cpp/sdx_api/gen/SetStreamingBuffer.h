#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set streaming buffer size.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------
    /// Size int  Streaming buffer size in msec
    ///

    class SetStreamingBuffer;
    typedef std::shared_ptr<SetStreamingBuffer> SetStreamingBufferPtr;
    
    
    class SetStreamingBuffer : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetStreamingBuffer();

      SetStreamingBuffer(int size);

      static SetStreamingBufferPtr create(int size);
      static SetStreamingBufferPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** size ****
      int size() const;
      void setSize(int size);
    };
    
  }
}

