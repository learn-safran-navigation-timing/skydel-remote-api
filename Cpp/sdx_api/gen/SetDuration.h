#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the simulation duration. The simulation will stop automatically when this duration is reached
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// Second int  The duration in seconds
    ///

    class SetDuration;
    typedef std::shared_ptr<SetDuration> SetDurationPtr;
    
    
    class SetDuration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetDuration();

      SetDuration(int second);

      static SetDurationPtr create(int second);
      static SetDurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** second ****
      int second() const;
      void setSecond(int second);
    };
    
  }
}

