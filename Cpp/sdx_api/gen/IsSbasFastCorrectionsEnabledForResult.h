#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSbasFastCorrectionsEnabledFor.
    ///
    /// Name      Type            Description
    /// --------- --------------- ----------------------------------------------------------------------------------------------------
    /// System    string          "GPS" or "SBAS"
    /// IsEnabled bool            True if corrections are enabled
    /// ErrorType optional string Comma separated error type to enable/disable. Accepted error types are "PSR offset" and "PSR error".
    ///                           Default value is "PSR error". Getter only accepts one error type.
    ///

    class IsSbasFastCorrectionsEnabledForResult;
    typedef std::shared_ptr<IsSbasFastCorrectionsEnabledForResult> IsSbasFastCorrectionsEnabledForResultPtr;
    
    
    class IsSbasFastCorrectionsEnabledForResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSbasFastCorrectionsEnabledForResult();

      IsSbasFastCorrectionsEnabledForResult(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});

      IsSbasFastCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});

      static IsSbasFastCorrectionsEnabledForResultPtr create(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});

      static IsSbasFastCorrectionsEnabledForResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});
      static IsSbasFastCorrectionsEnabledForResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);


      // **** errorType ****
      Sdx::optional<std::string> errorType() const;
      void setErrorType(const Sdx::optional<std::string>& errorType);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSbasFastCorrectionsEnabledForResult);
  }
}

