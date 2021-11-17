#pragma once

#include <memory>
#include "command_result.h"
#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLeapSecondFuture.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------
    /// Enabled bool If true, the future leap second event is set in the navigation message
    /// Seconds int  The future leap seconds value
    /// Date    date The event date
    ///

    class GetLeapSecondFutureResult;
    typedef std::shared_ptr<GetLeapSecondFutureResult> GetLeapSecondFutureResultPtr;
    
    
    class GetLeapSecondFutureResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetLeapSecondFutureResult();

      GetLeapSecondFutureResult(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date);
  
      static GetLeapSecondFutureResultPtr create(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date);
      static GetLeapSecondFutureResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** seconds ****
      int seconds() const;
      void setSeconds(int seconds);


      // **** date ****
      Sdx::Date date() const;
      void setDate(const Sdx::Date& date);
    };
  }
}

