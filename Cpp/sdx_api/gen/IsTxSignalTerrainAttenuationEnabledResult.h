#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsTxSignalTerrainAttenuationEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------------------------------------------------------
    /// Enabled bool If true, the power of interference and spoofing signals will be reduced based on the terrain profile between the transmitter and the receiver.
    ///

    class IsTxSignalTerrainAttenuationEnabledResult;
    typedef std::shared_ptr<IsTxSignalTerrainAttenuationEnabledResult> IsTxSignalTerrainAttenuationEnabledResultPtr;
    
    
    class IsTxSignalTerrainAttenuationEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsTxSignalTerrainAttenuationEnabledResult();

      IsTxSignalTerrainAttenuationEnabledResult(bool enabled);

      IsTxSignalTerrainAttenuationEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsTxSignalTerrainAttenuationEnabledResultPtr create(bool enabled);

      static IsTxSignalTerrainAttenuationEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsTxSignalTerrainAttenuationEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsTxSignalTerrainAttenuationEnabledResult);
  }
}

