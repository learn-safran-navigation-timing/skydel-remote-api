#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


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
      static const char* const TargetId;


      IsSpectrumVisibleResult();

      IsSpectrumVisibleResult(bool visible);

      IsSpectrumVisibleResult(CommandBasePtr relatedCommand, bool visible);

      static IsSpectrumVisibleResultPtr create(bool visible);

      static IsSpectrumVisibleResultPtr create(CommandBasePtr relatedCommand, bool visible);
      static IsSpectrumVisibleResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** visible ****
      bool visible() const;
      void setVisible(bool visible);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpectrumVisibleResult);
  }
}

