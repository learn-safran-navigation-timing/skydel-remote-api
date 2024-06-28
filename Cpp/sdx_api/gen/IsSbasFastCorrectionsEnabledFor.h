#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether specific errors type for this constellation should be compensated in SBAS fast corrections
    ///
    /// Name      Type            Description
    /// --------- --------------- ----------------------------------------------------------------------------------------------------
    /// System    string          "GPS" or "SBAS"
    /// ErrorType optional string Comma separated error type to enable/disable. Accepted error types are "PSR offset" and "PSR error".
    ///                           Default value is "PSR error". Getter only accepts one error type.
    ///

    class IsSbasFastCorrectionsEnabledFor;
    typedef std::shared_ptr<IsSbasFastCorrectionsEnabledFor> IsSbasFastCorrectionsEnabledForPtr;
    
    
    class IsSbasFastCorrectionsEnabledFor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSbasFastCorrectionsEnabledFor();

      IsSbasFastCorrectionsEnabledFor(const std::string& system, const std::optional<std::string>& errorType = {});

      static IsSbasFastCorrectionsEnabledForPtr create(const std::string& system, const std::optional<std::string>& errorType = {});
      static IsSbasFastCorrectionsEnabledForPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** errorType ****
      std::optional<std::string> errorType() const;
      void setErrorType(const std::optional<std::string>& errorType);
    };
    
  }
}

