#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the time interval of the Raw Data logging.
    ///
    /// 
    ///

    class GetRawDataLoggingInterval;
    typedef std::shared_ptr<GetRawDataLoggingInterval> GetRawDataLoggingIntervalPtr;
    
    
    class GetRawDataLoggingInterval : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetRawDataLoggingInterval();

      static GetRawDataLoggingIntervalPtr create();
      static GetRawDataLoggingIntervalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

