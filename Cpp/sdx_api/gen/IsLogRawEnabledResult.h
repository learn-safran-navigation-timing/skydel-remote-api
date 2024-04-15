#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


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
      static const char* const TargetId;


      IsLogRawEnabledResult();

      IsLogRawEnabledResult(bool enabled);

      IsLogRawEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsLogRawEnabledResultPtr create(bool enabled);

      static IsLogRawEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsLogRawEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsLogRawEnabledResult);
  }
}

