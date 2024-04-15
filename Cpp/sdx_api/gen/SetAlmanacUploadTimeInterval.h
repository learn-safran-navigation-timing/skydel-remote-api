#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set almanac upload interval in seconds. After the initial upload set with command 
    /// SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------
    /// System   string Must be "GPS"
    /// Interval int    Interval duration in sec. Accepted range is [3600..259200]
    ///

    class SetAlmanacUploadTimeInterval;
    typedef std::shared_ptr<SetAlmanacUploadTimeInterval> SetAlmanacUploadTimeIntervalPtr;
    
    
    class SetAlmanacUploadTimeInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetAlmanacUploadTimeInterval();

      SetAlmanacUploadTimeInterval(const std::string& system, int interval);

      static SetAlmanacUploadTimeIntervalPtr create(const std::string& system, int interval);
      static SetAlmanacUploadTimeIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** interval ****
      int interval() const;
      void setInterval(int interval);
    };
    
  }
}

