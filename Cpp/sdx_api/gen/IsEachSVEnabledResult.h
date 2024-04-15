#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsEachSVEnabled.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class IsEachSVEnabledResult;
    typedef std::shared_ptr<IsEachSVEnabledResult> IsEachSVEnabledResultPtr;
    
    
    class IsEachSVEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEachSVEnabledResult();

      IsEachSVEnabledResult(const std::string& system, const std::vector<bool>& enabled);

      IsEachSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);

      static IsEachSVEnabledResultPtr create(const std::string& system, const std::vector<bool>& enabled);

      static IsEachSVEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static IsEachSVEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsEachSVEnabledResult);
  }
}

