#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLosEnabledForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    The satellite's SV ID
    /// Enabled bool   Direct Line of Sight enabled or not
    ///

    class IsLosEnabledForSVResult;
    typedef std::shared_ptr<IsLosEnabledForSVResult> IsLosEnabledForSVResultPtr;
    
    
    class IsLosEnabledForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsLosEnabledForSVResult();

      IsLosEnabledForSVResult(const std::string& system, int svId, bool enabled);

      IsLosEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);

      static IsLosEnabledForSVResultPtr create(const std::string& system, int svId, bool enabled);

      static IsLosEnabledForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);
      static IsLosEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsLosEnabledForSVResult);
  }
}

