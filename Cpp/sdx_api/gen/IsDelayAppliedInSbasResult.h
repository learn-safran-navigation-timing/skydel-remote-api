#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsDelayAppliedInSbas.
    ///
    /// Name      Type Description
    /// --------- ---- --------------------------------------------
    /// IsEnabled bool True if offsets are applied in Sbas messages
    ///

    class IsDelayAppliedInSbasResult;
    typedef std::shared_ptr<IsDelayAppliedInSbasResult> IsDelayAppliedInSbasResultPtr;
    
    
    class IsDelayAppliedInSbasResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsDelayAppliedInSbasResult();

      IsDelayAppliedInSbasResult(bool isEnabled);

      IsDelayAppliedInSbasResult(CommandBasePtr relatedCommand, bool isEnabled);

      static IsDelayAppliedInSbasResultPtr create(bool isEnabled);

      static IsDelayAppliedInSbasResultPtr create(CommandBasePtr relatedCommand, bool isEnabled);
      static IsDelayAppliedInSbasResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsDelayAppliedInSbasResult);
  }
}

