#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsDektecAdjustedNoiseEnabled.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------------
    /// Enable bool True to enable Advance Jammer noise adjustment on Dektec output.
    ///

    class IsDektecAdjustedNoiseEnabledResult;
    typedef std::shared_ptr<IsDektecAdjustedNoiseEnabledResult> IsDektecAdjustedNoiseEnabledResultPtr;
    
    
    class IsDektecAdjustedNoiseEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsDektecAdjustedNoiseEnabledResult();

      IsDektecAdjustedNoiseEnabledResult(bool enable);

      IsDektecAdjustedNoiseEnabledResult(CommandBasePtr relatedCommand, bool enable);

      static IsDektecAdjustedNoiseEnabledResultPtr create(bool enable);

      static IsDektecAdjustedNoiseEnabledResultPtr create(CommandBasePtr relatedCommand, bool enable);
      static IsDektecAdjustedNoiseEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enable ****
      bool enable() const;
      void setEnable(bool enable);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsDektecAdjustedNoiseEnabledResult);
  }
}

