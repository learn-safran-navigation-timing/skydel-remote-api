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
    /// Result of GetSignalEnabledForEachPrn
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------
    /// Signal  string     Signal key - see command description for possible values
    /// Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first PRN, index 1 => second PRN, etc).
    ///

    class GetSignalEnabledForEachPrnResult;
    typedef std::shared_ptr<GetSignalEnabledForEachPrnResult> GetSignalEnabledForEachPrnResultPtr;
    
    
    class GetSignalEnabledForEachPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSignalEnabledForEachPrnResult();

      GetSignalEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
  
      static GetSignalEnabledForEachPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
      static GetSignalEnabledForEachPrnResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

