#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.
    /// This value has no effect when GPS start time is "custom" or "computer".
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------------------------------------------------------
    /// Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver
    ///

    class SetStartTimeOffset;
    typedef std::shared_ptr<SetStartTimeOffset> SetStartTimeOffsetPtr;
    
    
    class SetStartTimeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetStartTimeOffset();

      SetStartTimeOffset(int offset);

      static SetStartTimeOffsetPtr create(int offset);
      static SetStartTimeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    
  }
}

