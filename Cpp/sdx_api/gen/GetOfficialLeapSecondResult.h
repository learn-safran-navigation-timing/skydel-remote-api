#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOfficialLeapSecond
    ///
    /// Name       Type Description
    /// ---------- ---- -----------------
    /// LeapSecond int  Leap second value
    ///

    class GetOfficialLeapSecondResult;
    typedef std::shared_ptr<GetOfficialLeapSecondResult> GetOfficialLeapSecondResultPtr;
    
    
    class GetOfficialLeapSecondResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetOfficialLeapSecondResult();

      GetOfficialLeapSecondResult(int leapSecond);

      GetOfficialLeapSecondResult(CommandBasePtr relatedCommand, int leapSecond);

      static GetOfficialLeapSecondResultPtr create(int leapSecond);

      static GetOfficialLeapSecondResultPtr create(CommandBasePtr relatedCommand, int leapSecond);
      static GetOfficialLeapSecondResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** leapSecond ****
      int leapSecond() const;
      void setLeapSecond(int leapSecond);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetOfficialLeapSecondResult);
  }
}

