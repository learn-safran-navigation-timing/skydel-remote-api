#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the 0th PPS' date time
    ///
    /// Name    Type     Description
    /// ------- -------- --------------------------------------------------------------
    /// GpsTime datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetPps0GpsTime;
    typedef std::shared_ptr<SetPps0GpsTime> SetPps0GpsTimePtr;
    
    
    class SetPps0GpsTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPps0GpsTime();

      SetPps0GpsTime(const Sdx::DateTime& gpsTime);

      static SetPps0GpsTimePtr create(const Sdx::DateTime& gpsTime);
      static SetPps0GpsTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** gpsTime ****
      Sdx::DateTime gpsTime() const;
      void setGpsTime(const Sdx::DateTime& gpsTime);
    };
    
  }
}

