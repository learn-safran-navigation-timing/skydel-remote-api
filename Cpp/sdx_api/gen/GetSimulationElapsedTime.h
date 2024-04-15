#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get simulation elapsed time in milliseconds.
    ///
    /// 
    ///

    class GetSimulationElapsedTime;
    typedef std::shared_ptr<GetSimulationElapsedTime> GetSimulationElapsedTimePtr;
    
    
    class GetSimulationElapsedTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSimulationElapsedTime();

      static GetSimulationElapsedTimePtr create();
      static GetSimulationElapsedTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

