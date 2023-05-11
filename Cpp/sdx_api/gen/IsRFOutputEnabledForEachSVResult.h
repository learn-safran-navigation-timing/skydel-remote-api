#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsRFOutputEnabledForEachSV.
    ///
    /// Name    Type       Description
    /// ------- ---------- -------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).
    ///

    class IsRFOutputEnabledForEachSVResult;
    typedef std::shared_ptr<IsRFOutputEnabledForEachSVResult> IsRFOutputEnabledForEachSVResultPtr;
    
    
    class IsRFOutputEnabledForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsRFOutputEnabledForEachSVResult();

      IsRFOutputEnabledForEachSVResult(const std::string& system, const std::vector<bool>& enabled);

      IsRFOutputEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);

      static IsRFOutputEnabledForEachSVResultPtr create(const std::string& system, const std::vector<bool>& enabled);

      static IsRFOutputEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static IsRFOutputEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsRFOutputEnabledForEachSVResult);
  }
}

