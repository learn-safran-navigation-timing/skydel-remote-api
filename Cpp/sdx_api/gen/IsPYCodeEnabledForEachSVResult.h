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
    /// Result of IsPYCodeEnabledForEachSV.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1P", "L2P"
    /// Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class IsPYCodeEnabledForEachSVResult;
    typedef std::shared_ptr<IsPYCodeEnabledForEachSVResult> IsPYCodeEnabledForEachSVResultPtr;
    
    
    class IsPYCodeEnabledForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYCodeEnabledForEachSVResult();

      IsPYCodeEnabledForEachSVResult(const std::string& signal, const std::vector<bool>& enabled);

      IsPYCodeEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);

      static IsPYCodeEnabledForEachSVResultPtr create(const std::string& signal, const std::vector<bool>& enabled);

      static IsPYCodeEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled);
      static IsPYCodeEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsPYCodeEnabledForEachSVResult);
  }
}

