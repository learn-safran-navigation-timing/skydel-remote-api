#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation duration.
    ///
    /// 
    ///

    class GetDuration;
    typedef std::shared_ptr<GetDuration> GetDurationPtr;
    
    
    class GetDuration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDuration();

      static GetDurationPtr create();
      static GetDurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

