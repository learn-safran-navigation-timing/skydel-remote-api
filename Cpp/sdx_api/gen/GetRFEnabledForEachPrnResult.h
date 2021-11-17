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
    /// Result of GetRFEnabledForEachPrn.
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool RF is enabled when value is True. Zero based index (index 0 => first PRN, index 1 => second PRN, etc).
    ///

    class GetRFEnabledForEachPrnResult;
    typedef std::shared_ptr<GetRFEnabledForEachPrnResult> GetRFEnabledForEachPrnResultPtr;
    
    
    class GetRFEnabledForEachPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetRFEnabledForEachPrnResult();

      GetRFEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
  
      static GetRFEnabledForEachPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static GetRFEnabledForEachPrnResultPtr dynamicCast(CommandBasePtr ptr);
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

