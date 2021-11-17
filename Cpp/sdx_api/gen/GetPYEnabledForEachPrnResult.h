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
    /// Result of GetPYEnabledForEachPrn.
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------------------
    /// Signal  string     Signal key - see command description for possible values
    /// Enabled array bool Enable P(Y)-Code if True, otherwise it is P-Code only. Zero based index (index 0 => PRN 1, index 1 => PRN 2, etc).
    ///

    class GetPYEnabledForEachPrnResult;
    typedef std::shared_ptr<GetPYEnabledForEachPrnResult> GetPYEnabledForEachPrnResultPtr;
    
    
    class GetPYEnabledForEachPrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPYEnabledForEachPrnResult();

      GetPYEnabledForEachPrnResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
  
      static GetPYEnabledForEachPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
      static GetPYEnabledForEachPrnResultPtr dynamicCast(CommandBasePtr ptr);
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

