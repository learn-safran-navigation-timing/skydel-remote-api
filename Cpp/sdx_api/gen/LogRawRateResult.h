#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLogRawRate.
    ///
    /// Name Type Description
    /// ---- ---- --------------------------------------
    /// Rate int  Accepted rates are 10, 100 and 1000 Hz
    ///

    class LogRawRateResult;
    typedef std::shared_ptr<LogRawRateResult> LogRawRateResultPtr;
    
    
    class LogRawRateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      LogRawRateResult();

      LogRawRateResult(int rate);

      LogRawRateResult(CommandBasePtr relatedCommand, int rate);

      static LogRawRateResultPtr create(int rate);

      static LogRawRateResultPtr create(CommandBasePtr relatedCommand, int rate);
      static LogRawRateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** rate ****
      int rate() const;
      void setRate(int rate);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(LogRawRateResult);
  }
}

