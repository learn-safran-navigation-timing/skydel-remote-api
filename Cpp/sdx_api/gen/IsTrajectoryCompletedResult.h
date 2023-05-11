#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTrajectoryCompleted.
    ///
    /// Name        Type Description
    /// ----------- ---- ------------------------------------------
    /// IsCompleted bool Whether the trajectory is completed or not
    ///

    class IsTrajectoryCompletedResult;
    typedef std::shared_ptr<IsTrajectoryCompletedResult> IsTrajectoryCompletedResultPtr;
    
    
    class IsTrajectoryCompletedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsTrajectoryCompletedResult();

      IsTrajectoryCompletedResult(bool isCompleted);

      IsTrajectoryCompletedResult(CommandBasePtr relatedCommand, bool isCompleted);

      static IsTrajectoryCompletedResultPtr create(bool isCompleted);

      static IsTrajectoryCompletedResultPtr create(CommandBasePtr relatedCommand, bool isCompleted);
      static IsTrajectoryCompletedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isCompleted ****
      bool isCompleted() const;
      void setIsCompleted(bool isCompleted);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsTrajectoryCompletedResult);
  }
}

