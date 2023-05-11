#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetRawDataLoggingInterval.
    ///
    /// Name         Type Description
    /// ------------ ---- -------------------------
    /// Days         int  Interval in days.
    /// Hours        int  Interval in hours.
    /// Minutes      int  Interval in minutes.
    /// Seconds      int  Interval in seconds.
    /// Milliseconds int  Interval in milliseconds.
    ///

    class RawDataLoggingIntervalResult;
    typedef std::shared_ptr<RawDataLoggingIntervalResult> RawDataLoggingIntervalResultPtr;
    
    
    class RawDataLoggingIntervalResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RawDataLoggingIntervalResult();

      RawDataLoggingIntervalResult(int days, int hours, int minutes, int seconds, int milliseconds);

      RawDataLoggingIntervalResult(CommandBasePtr relatedCommand, int days, int hours, int minutes, int seconds, int milliseconds);

      static RawDataLoggingIntervalResultPtr create(int days, int hours, int minutes, int seconds, int milliseconds);

      static RawDataLoggingIntervalResultPtr create(CommandBasePtr relatedCommand, int days, int hours, int minutes, int seconds, int milliseconds);
      static RawDataLoggingIntervalResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(RawDataLoggingIntervalResult);
  }
}

