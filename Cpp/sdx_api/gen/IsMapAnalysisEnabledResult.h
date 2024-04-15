#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsMapAnalysisEnabled.
    ///
    /// Name Type Description
    /// ---- ---- -------------
    /// Show bool Show map flag
    ///

    class IsMapAnalysisEnabledResult;
    typedef std::shared_ptr<IsMapAnalysisEnabledResult> IsMapAnalysisEnabledResultPtr;
    
    
    class IsMapAnalysisEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsMapAnalysisEnabledResult();

      IsMapAnalysisEnabledResult(bool show);

      IsMapAnalysisEnabledResult(CommandBasePtr relatedCommand, bool show);

      static IsMapAnalysisEnabledResultPtr create(bool show);

      static IsMapAnalysisEnabledResultPtr create(CommandBasePtr relatedCommand, bool show);
      static IsMapAnalysisEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** show ****
      bool show() const;
      void setShow(bool show);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsMapAnalysisEnabledResult);
  }
}

