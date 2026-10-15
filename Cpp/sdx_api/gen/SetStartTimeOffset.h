#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Time offset between the simulated GPS time and the selected real-time synchronized time source (Computer Synchronized, NTP or GPS) at the beginning of the simulation.
    /// This setting has no effect with the Custom and Computer start time modes.
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------------------------------------------------------------------------------------
    /// Offset int  Time offset, in seconds, between the simulated GPS time and the time given by the selected real-time synchronized time source.
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

