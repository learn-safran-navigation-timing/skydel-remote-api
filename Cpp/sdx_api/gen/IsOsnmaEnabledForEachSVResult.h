#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsOsnmaEnabledForEachSV.
    ///
    /// Name    Type       Description
    /// ------- ---------- -------------------------------------------------------------------------------------------------------------
    /// Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).
    ///

    class IsOsnmaEnabledForEachSVResult;
    typedef std::shared_ptr<IsOsnmaEnabledForEachSVResult> IsOsnmaEnabledForEachSVResultPtr;
    
    
    class IsOsnmaEnabledForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsOsnmaEnabledForEachSVResult();

      IsOsnmaEnabledForEachSVResult(const std::vector<bool>& enabled);

      IsOsnmaEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::vector<bool>& enabled);

      static IsOsnmaEnabledForEachSVResultPtr create(const std::vector<bool>& enabled);

      static IsOsnmaEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<bool>& enabled);
      static IsOsnmaEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsOsnmaEnabledForEachSVResult);
  }
}

