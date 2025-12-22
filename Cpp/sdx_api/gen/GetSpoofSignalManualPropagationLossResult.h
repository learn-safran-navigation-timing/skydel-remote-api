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
    /// Result of GetSpoofSignalManualPropagationLoss.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------------------------------------------------------------------------------------------
    /// PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class GetSpoofSignalManualPropagationLossResult;
    typedef std::shared_ptr<GetSpoofSignalManualPropagationLossResult> GetSpoofSignalManualPropagationLossResultPtr;
    
    
    class GetSpoofSignalManualPropagationLossResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofSignalManualPropagationLossResult();

      GetSpoofSignalManualPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      GetSpoofSignalManualPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetSpoofSignalManualPropagationLossResultPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetSpoofSignalManualPropagationLossResultPtr create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);
      static GetSpoofSignalManualPropagationLossResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofSignalManualPropagationLossResult);
  }
}

