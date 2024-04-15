#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the next leap second event
    ///
    /// 
    ///

    class GetLeapSecondFuture;
    typedef std::shared_ptr<GetLeapSecondFuture> GetLeapSecondFuturePtr;
    
    
    class GetLeapSecondFuture : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetLeapSecondFuture();

      static GetLeapSecondFuturePtr create();
      static GetLeapSecondFuturePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

