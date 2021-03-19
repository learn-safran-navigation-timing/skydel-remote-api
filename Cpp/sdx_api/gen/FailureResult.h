#pragma once

#include <memory>
#include "command_result.h"
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

      FailureResult(CommandBasePtr relatedCommand, const std::string& errorMsg);
  
      static FailureResultPtr create(CommandBasePtr relatedCommand, const std::string& errorMsg);
      static FailureResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** errorMsg ****
      std::string errorMsg() const;
      void setErrorMsg(const std::string& errorMsg);
    };
  }
}

