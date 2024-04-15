#pragma once

#include <memory>
#include "command_base.h"

#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the next leap second event
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------
    /// Enabled bool If true, the future leap second event is set in the navigation message
    /// Seconds int  The future leap seconds value
    /// Date    date The event date
    ///

    class SetLeapSecondFuture;
    typedef std::shared_ptr<SetLeapSecondFuture> SetLeapSecondFuturePtr;
    
    
    class SetLeapSecondFuture : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetLeapSecondFuture();

      SetLeapSecondFuture(bool enabled, int seconds, const Sdx::Date& date);

      static SetLeapSecondFuturePtr create(bool enabled, int seconds, const Sdx::Date& date);
      static SetLeapSecondFuturePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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

