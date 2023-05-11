#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogRinexEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class IsLogRinexEnabledResult;
    typedef std::shared_ptr<IsLogRinexEnabledResult> IsLogRinexEnabledResultPtr;
    
    
    class IsLogRinexEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLogRinexEnabledResult();

      IsLogRinexEnabledResult(bool enabled);

      IsLogRinexEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsLogRinexEnabledResultPtr create(bool enabled);

      static IsLogRinexEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsLogRinexEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsLogRinexEnabledResult);
  }
}

