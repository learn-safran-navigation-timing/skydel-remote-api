#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Rate logging of NMEA data
    ///
    /// 
    ///

    class GetLogNmeaRate;
    typedef std::shared_ptr<GetLogNmeaRate> GetLogNmeaRatePtr;
    
    
    class GetLogNmeaRate : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetLogNmeaRate();

      static GetLogNmeaRatePtr create();
      static GetLogNmeaRatePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

