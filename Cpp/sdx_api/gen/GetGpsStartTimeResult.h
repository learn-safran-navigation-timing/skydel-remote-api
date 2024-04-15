#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsStartTime.
    ///
    /// Name       Type     Description
    /// ---------- -------- ------------------------------------------------------------------------------------------------
    /// StartTime  datetime GPS date and time when the simulation started (it is the GPS time expressed in Gregorian format)
    /// LeapSecond int      The number of leap seconds to convert GPS date and time into UTC
    ///

    class GetGpsStartTimeResult;
    typedef std::shared_ptr<GetGpsStartTimeResult> GetGpsStartTimeResultPtr;
    
    
    class GetGpsStartTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsStartTimeResult();

      GetGpsStartTimeResult(const Sdx::DateTime& startTime, int leapSecond);

      GetGpsStartTimeResult(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond);

      static GetGpsStartTimeResultPtr create(const Sdx::DateTime& startTime, int leapSecond);

      static GetGpsStartTimeResultPtr create(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond);
      static GetGpsStartTimeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** startTime ****
      Sdx::DateTime startTime() const;
      void setStartTime(const Sdx::DateTime& startTime);


      // **** leapSecond ****
      int leapSecond() const;
      void setLeapSecond(int leapSecond);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsStartTimeResult);
  }
}

