#pragma once

#include <memory>
#include "command_result.h"


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


      IsMapAnalysisEnabledResult();

      IsMapAnalysisEnabledResult(CommandBasePtr relatedCommand, bool show);
  
      static IsMapAnalysisEnabledResultPtr create(CommandBasePtr relatedCommand, bool show);
      static IsMapAnalysisEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** show ****
      bool show() const;
      void setShow(bool show);
    };
  }
}

