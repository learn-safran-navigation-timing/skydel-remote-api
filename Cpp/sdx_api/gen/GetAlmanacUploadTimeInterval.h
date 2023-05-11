#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get almanac upload interval in seconds. After the initial upload set with command 
    /// SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.
    ///
    /// 
    ///

    class GetAlmanacUploadTimeInterval;
    typedef std::shared_ptr<GetAlmanacUploadTimeInterval> GetAlmanacUploadTimeIntervalPtr;
    
    
    class GetAlmanacUploadTimeInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAlmanacUploadTimeInterval();

      static GetAlmanacUploadTimeIntervalPtr create();
      static GetAlmanacUploadTimeIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

