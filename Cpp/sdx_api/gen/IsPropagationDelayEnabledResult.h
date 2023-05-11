#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPropagationDelayEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.
    ///

    class IsPropagationDelayEnabledResult;
    typedef std::shared_ptr<IsPropagationDelayEnabledResult> IsPropagationDelayEnabledResultPtr;
    
    
    class IsPropagationDelayEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPropagationDelayEnabledResult();

      IsPropagationDelayEnabledResult(const std::string& system, bool enabled);

      IsPropagationDelayEnabledResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled);

      static IsPropagationDelayEnabledResultPtr create(const std::string& system, bool enabled);

      static IsPropagationDelayEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool enabled);
      static IsPropagationDelayEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsPropagationDelayEnabledResult);
  }
}

