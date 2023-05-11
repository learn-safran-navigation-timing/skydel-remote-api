#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns the last known leap second date
    ///
    /// 
    ///

    class GetLastLeapSecondDate;
    typedef std::shared_ptr<GetLastLeapSecondDate> GetLastLeapSecondDatePtr;
    
    
    class GetLastLeapSecondDate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetLastLeapSecondDate();

      static GetLastLeapSecondDatePtr create();
      static GetLastLeapSecondDatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

