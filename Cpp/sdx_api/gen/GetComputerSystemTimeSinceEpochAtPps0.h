#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get  the computer system time since epoch at PPS0, for the computer running this Skydel instance.
    /// Use this command after StartPPS.
    ///
    /// 
    ///

    class GetComputerSystemTimeSinceEpochAtPps0;
    typedef std::shared_ptr<GetComputerSystemTimeSinceEpochAtPps0> GetComputerSystemTimeSinceEpochAtPps0Ptr;
    
    
    class GetComputerSystemTimeSinceEpochAtPps0 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetComputerSystemTimeSinceEpochAtPps0();

      static GetComputerSystemTimeSinceEpochAtPps0Ptr create();
      static GetComputerSystemTimeSinceEpochAtPps0Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

