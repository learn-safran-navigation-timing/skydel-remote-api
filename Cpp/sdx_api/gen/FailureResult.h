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
    /// When command failed
    ///
    /// Name     Type   Description
    /// -------- ------ -------------
    /// ErrorMsg string Error message
    ///

    class FailureResult;
    typedef std::shared_ptr<FailureResult> FailureResultPtr;
    
    
    class FailureResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      FailureResult();

      FailureResult(const std::string& errorMsg);

      FailureResult(CommandBasePtr relatedCommand, const std::string& errorMsg);

      static FailureResultPtr create(const std::string& errorMsg);

      static FailureResultPtr create(CommandBasePtr relatedCommand, const std::string& errorMsg);
      static FailureResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      inline virtual bool isSuccess() const override { return false; }


      // **** errorMsg ****
      std::string errorMsg() const;
      void setErrorMsg(const std::string& errorMsg);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(FailureResult);
  }
}

