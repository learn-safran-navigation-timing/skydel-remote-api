#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLastLeapSecondDate.
    ///
    /// Name Type Description
    /// ---- ---- ----------------
    /// Date date Leap second date
    ///

    class GetLastLeapSecondDateResult;
    typedef std::shared_ptr<GetLastLeapSecondDateResult> GetLastLeapSecondDateResultPtr;
    
    
    class GetLastLeapSecondDateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetLastLeapSecondDateResult();

      GetLastLeapSecondDateResult(const Sdx::Date& date);

      GetLastLeapSecondDateResult(CommandBasePtr relatedCommand, const Sdx::Date& date);

      static GetLastLeapSecondDateResultPtr create(const Sdx::Date& date);

      static GetLastLeapSecondDateResultPtr create(CommandBasePtr relatedCommand, const Sdx::Date& date);
      static GetLastLeapSecondDateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** date ****
      Sdx::Date date() const;
      void setDate(const Sdx::Date& date);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetLastLeapSecondDateResult);
  }
}

