#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNmeaLoggerSerialPortDelay.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------
    /// Delay int  Delay from 0 to 100 milliseconds.
    ///

    class GetNmeaLoggerSerialPortDelayResult;
    typedef std::shared_ptr<GetNmeaLoggerSerialPortDelayResult> GetNmeaLoggerSerialPortDelayResultPtr;
    
    
    class GetNmeaLoggerSerialPortDelayResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNmeaLoggerSerialPortDelayResult();

      GetNmeaLoggerSerialPortDelayResult(int delay);

      GetNmeaLoggerSerialPortDelayResult(CommandBasePtr relatedCommand, int delay);

      static GetNmeaLoggerSerialPortDelayResultPtr create(int delay);

      static GetNmeaLoggerSerialPortDelayResultPtr create(CommandBasePtr relatedCommand, int delay);
      static GetNmeaLoggerSerialPortDelayResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** delay ****
      int delay() const;
      void setDelay(int delay);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNmeaLoggerSerialPortDelayResult);
  }
}

