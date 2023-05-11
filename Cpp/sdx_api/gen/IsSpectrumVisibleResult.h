#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSpectrumVisible.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------
    /// Visible bool Show spectrum flag
    ///

    class IsSpectrumVisibleResult;
    typedef std::shared_ptr<IsSpectrumVisibleResult> IsSpectrumVisibleResultPtr;
    
    
    class IsSpectrumVisibleResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSpectrumVisibleResult();

      IsSpectrumVisibleResult(bool visible);

      IsSpectrumVisibleResult(CommandBasePtr relatedCommand, bool visible);

      static IsSpectrumVisibleResultPtr create(bool visible);

      static IsSpectrumVisibleResultPtr create(CommandBasePtr relatedCommand, bool visible);
      static IsSpectrumVisibleResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** visible ****
      bool visible() const;
      void setVisible(bool visible);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSpectrumVisibleResult);
  }
}

