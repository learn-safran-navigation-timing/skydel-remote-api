#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the time interval of the Raw Data logging.
    ///
    /// Name         Type Description
    /// ------------ ---- -------------------------
    /// Days         int  Interval in days.
    /// Hours        int  Interval in hours.
    /// Minutes      int  Interval in minutes.
    /// Seconds      int  Interval in seconds.
    /// Milliseconds int  Interval in milliseconds.
    ///

    class SetRawDataLoggingInterval;
    typedef std::shared_ptr<SetRawDataLoggingInterval> SetRawDataLoggingIntervalPtr;
    
    
    class SetRawDataLoggingInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetRawDataLoggingInterval();

      SetRawDataLoggingInterval(int days, int hours, int minutes, int seconds, int milliseconds);

      static SetRawDataLoggingIntervalPtr create(int days, int hours, int minutes, int seconds, int milliseconds);
      static SetRawDataLoggingIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** days ****
      int days() const;
      void setDays(int days);


      // **** hours ****
      int hours() const;
      void setHours(int hours);


      // **** minutes ****
      int minutes() const;
      void setMinutes(int minutes);


      // **** seconds ****
      int seconds() const;
      void setSeconds(int seconds);


      // **** milliseconds ****
      int milliseconds() const;
      void setMilliseconds(int milliseconds);
    };
    
  }
}

