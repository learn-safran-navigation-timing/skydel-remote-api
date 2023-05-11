#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Rate logging of raw data
    ///
    /// 
    ///

    class GetLogRawRate;
    typedef std::shared_ptr<GetLogRawRate> GetLogRawRatePtr;
    
    
    class GetLogRawRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetLogRawRate();

      static GetLogRawRatePtr create();
      static GetLogRawRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

