#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Time offset between the simulated GPS time and the selected real-time synchronized time source (Computer Synchronized, NTP or GPS) at the beginning of the simulation.
    /// This setting has no effect with the Custom and Computer start time modes.
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

