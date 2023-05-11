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
    /// Result of IsSVEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------------------------------------------------------------------------
    /// System  string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    The satellite's SV ID (use 0 for all SVs).
    /// Enabled bool   The satellite will be present/absent from the constellation
    ///

    class IsSVEnabledResult;
    typedef std::shared_ptr<IsSVEnabledResult> IsSVEnabledResultPtr;
    
    
    class IsSVEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSVEnabledResult();

      IsSVEnabledResult(const std::string& system, int svId, bool enabled);

      IsSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);

      static IsSVEnabledResultPtr create(const std::string& system, int svId, bool enabled);

      static IsSVEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled);
      static IsSVEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSVEnabledResult);
  }
}

