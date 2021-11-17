#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogRawEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, file will be created during simulation
    ///

    class IsLogRawEnabledResult;
    typedef std::shared_ptr<IsLogRawEnabledResult> IsLogRawEnabledResultPtr;
    
    
    class IsLogRawEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogRawEnabledResult();

      IsLogRawEnabledResult(CommandBasePtr relatedCommand, bool enabled);
  
      static IsLogRawEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsLogRawEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

