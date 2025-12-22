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
    /// Result of GetIntTxSignalManualPropagationLoss.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------------------------------------------------------------------------------------------
    /// PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class GetIntTxSignalManualPropagationLossResult;
    typedef std::shared_ptr<GetIntTxSignalManualPropagationLossResult> GetIntTxSignalManualPropagationLossResultPtr;
    
    
    class GetIntTxSignalManualPropagationLossResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxSignalManualPropagationLossResult();

      GetIntTxSignalManualPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      GetIntTxSignalManualPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetIntTxSignalManualPropagationLossResultPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetIntTxSignalManualPropagationLossResultPtr create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);
      static GetIntTxSignalManualPropagationLossResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** propagationLoss ****
      double propagationLoss() const;
      void setPropagationLoss(double propagationLoss);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxSignalManualPropagationLossResult);
  }
}

