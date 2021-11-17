#pragma once

#include <memory>
#include "command_result.h"


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

      IsTrajectoryCompletedResult(CommandBasePtr relatedCommand, bool isCompleted);
  
      static IsTrajectoryCompletedResultPtr create(CommandBasePtr relatedCommand, bool isCompleted);
      static IsTrajectoryCompletedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isCompleted ****
      bool isCompleted() const;
      void setIsCompleted(bool isCompleted);
    };
  }
}

