#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAlmanacInitialUploadTimeOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------
    /// System string Must be "GPS"
    /// Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]
    ///

    class GetAlmanacInitialUploadTimeOffsetResult;
    typedef std::shared_ptr<GetAlmanacInitialUploadTimeOffsetResult> GetAlmanacInitialUploadTimeOffsetResultPtr;
    
    
    class GetAlmanacInitialUploadTimeOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAlmanacInitialUploadTimeOffsetResult();

      GetAlmanacInitialUploadTimeOffsetResult(const std::string& system, int offset);

      GetAlmanacInitialUploadTimeOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset);

      static GetAlmanacInitialUploadTimeOffsetResultPtr create(const std::string& system, int offset);

      static GetAlmanacInitialUploadTimeOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int offset);
      static GetAlmanacInitialUploadTimeOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** offset ****
      int offset() const;
      void setOffset(int offset);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetAlmanacInitialUploadTimeOffsetResult);
  }
}

