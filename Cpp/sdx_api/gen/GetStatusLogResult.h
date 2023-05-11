#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/LogRecord.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStatusLog.
    ///
    /// Name    Type            Description
    /// ------- --------------- ----------------
    /// Records array LogRecord The log records.
    ///

    class GetStatusLogResult;
    typedef std::shared_ptr<GetStatusLogResult> GetStatusLogResultPtr;
    
    
    class GetStatusLogResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetStatusLogResult();

      GetStatusLogResult(const std::vector<Sdx::LogRecord>& records);

      GetStatusLogResult(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records);

      static GetStatusLogResultPtr create(const std::vector<Sdx::LogRecord>& records);

      static GetStatusLogResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records);
      static GetStatusLogResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** records ****
      std::vector<Sdx::LogRecord> records() const;
      void setRecords(const std::vector<Sdx::LogRecord>& records);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetStatusLogResult);
  }
}

