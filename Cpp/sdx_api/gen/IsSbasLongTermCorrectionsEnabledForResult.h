#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSbasLongTermCorrectionsEnabledFor.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------
    /// System    string As of today, only "GPS" is supported.
    /// IsEnabled bool   True if corrections are enabled.
    ///

    class IsSbasLongTermCorrectionsEnabledForResult;
    typedef std::shared_ptr<IsSbasLongTermCorrectionsEnabledForResult> IsSbasLongTermCorrectionsEnabledForResultPtr;
    
    
    class IsSbasLongTermCorrectionsEnabledForResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSbasLongTermCorrectionsEnabledForResult();

      IsSbasLongTermCorrectionsEnabledForResult(const std::string& system, bool isEnabled);

      IsSbasLongTermCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled);

      static IsSbasLongTermCorrectionsEnabledForResultPtr create(const std::string& system, bool isEnabled);

      static IsSbasLongTermCorrectionsEnabledForResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled);
      static IsSbasLongTermCorrectionsEnabledForResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSbasLongTermCorrectionsEnabledForResult);
  }
}

