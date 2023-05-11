#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// When command succeed.
    ///
    /// 
    ///

    class SuccessResult;
    typedef std::shared_ptr<SuccessResult> SuccessResultPtr;
    
    
    class SuccessResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SuccessResult();

      SuccessResult(CommandBasePtr relatedCommand);

      static SuccessResultPtr create(CommandBasePtr relatedCommand);
      static SuccessResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(SuccessResult);
  }
}

