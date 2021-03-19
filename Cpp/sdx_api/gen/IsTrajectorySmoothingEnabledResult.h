#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTrajectorySmoothingEnabled
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------
    /// Enabled bool If true, trajectory will be smoothed during simulation
    ///

    class IsTrajectorySmoothingEnabledResult;
    typedef std::shared_ptr<IsTrajectorySmoothingEnabledResult> IsTrajectorySmoothingEnabledResultPtr;
    
    
    class IsTrajectorySmoothingEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsTrajectorySmoothingEnabledResult();

      IsTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

