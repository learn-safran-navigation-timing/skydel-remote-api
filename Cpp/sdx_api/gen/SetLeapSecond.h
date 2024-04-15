#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the UTC leap seconds added since GPS epoch.
    ///
    /// Name       Type Description
    /// ---------- ---- ----------------------------------------------------------------
    /// LeapSecond int  The number of leap seconds to convert GPS date and time into UTC
    ///

    class SetLeapSecond;
    typedef std::shared_ptr<SetLeapSecond> SetLeapSecondPtr;
    
    
    class SetLeapSecond : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetLeapSecond();

      SetLeapSecond(int leapSecond);

      static SetLeapSecondPtr create(int leapSecond);
      static SetLeapSecondPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** leapSecond ****
      int leapSecond() const;
      void setLeapSecond(int leapSecond);
    };
    
  }
}

