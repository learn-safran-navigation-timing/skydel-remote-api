#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEngineLatency.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------
    /// Latency int  Engine latency in msec
    ///

    class GetEngineLatencyResult;
    typedef std::shared_ptr<GetEngineLatencyResult> GetEngineLatencyResultPtr;
    
    
    class GetEngineLatencyResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEngineLatencyResult();

      GetEngineLatencyResult(int latency);

      GetEngineLatencyResult(CommandBasePtr relatedCommand, int latency);

      static GetEngineLatencyResultPtr create(int latency);

      static GetEngineLatencyResultPtr create(CommandBasePtr relatedCommand, int latency);
      static GetEngineLatencyResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** latency ****
      int latency() const;
      void setLatency(int latency);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetEngineLatencyResult);
  }
}

