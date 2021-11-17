#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLOSEnabledForEachPrn.
    ///
    /// Name    Type       Description
    /// ------- ---------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool Direct Line of Sight enabled or not. Zero based index (index 0 => first PRN (Slot for GLONASS, SV ID for QSZZ and NavIC), index 1 => second PRN (Slot for GLONASS, SV ID for QSZZ), etc).
    ///

    class IsLOSEnabledForEachPrnResult;
    typedef std::shared_ptr<IsLOSEnabledForEachPrnResult> IsLOSEnabledForEachPrnResultPtr;
    
    
    class IsLOSEnabledForEachPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsLOSEnabledForEachPrnResult();

      IsLOSEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
  
      static IsLOSEnabledForEachPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static IsLOSEnabledForEachPrnResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

