#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.
    /// This value has no effect when GPS start time is "custom" or "computer".
    ///
    /// 
    ///

    class GetStartTimeOffset;
    typedef std::shared_ptr<GetStartTimeOffset> GetStartTimeOffsetPtr;
    
    
    class GetStartTimeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetStartTimeOffset();

      static GetStartTimeOffsetPtr create();
      static GetStartTimeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

