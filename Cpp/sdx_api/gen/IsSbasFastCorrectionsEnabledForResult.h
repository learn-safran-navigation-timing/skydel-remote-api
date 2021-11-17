#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSbasFastCorrectionsEnabledFor.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------
    /// System    string "GPS" or "SBAS"
    /// IsEnabled bool   True if corrections are enabled
    ///

    class IsSbasFastCorrectionsEnabledForResult;
    typedef std::shared_ptr<IsSbasFastCorrectionsEnabledForResult> IsSbasFastCorrectionsEnabledForResultPtr;
    
    
    class IsSbasFastCorrectionsEnabledForResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSbasFastCorrectionsEnabledForResult();

      IsSbasFastCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled);
  
      static IsSbasFastCorrectionsEnabledForResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled);
      static IsSbasFastCorrectionsEnabledForResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
  }
}

