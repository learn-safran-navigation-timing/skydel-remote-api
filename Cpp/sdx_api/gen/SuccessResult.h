#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


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
      static const char* const TargetId;


      SuccessResult();

      SuccessResult(CommandBasePtr relatedCommand);

      static SuccessResultPtr create(CommandBasePtr relatedCommand);
      static SuccessResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(SuccessResult);
  }
}

