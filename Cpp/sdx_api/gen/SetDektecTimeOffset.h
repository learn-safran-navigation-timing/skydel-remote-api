#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set a time offset in nanoseconds to be applied to a Dektec radio.
    ///
    /// Name       Type Description
    /// ---------- ---- ------------------------------------
    /// Output     int  Output index (zero based).
    /// TimeOffset int  Time offset to apply in nanoseconds.
    ///

    class SetDektecTimeOffset;
    typedef std::shared_ptr<SetDektecTimeOffset> SetDektecTimeOffsetPtr;
    
    
    class SetDektecTimeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDektecTimeOffset();

      SetDektecTimeOffset(int output, int timeOffset);

      static SetDektecTimeOffsetPtr create(int output, int timeOffset);
      static SetDektecTimeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** timeOffset ****
      int timeOffset() const;
      void setTimeOffset(int timeOffset);
    };
    
  }
}

