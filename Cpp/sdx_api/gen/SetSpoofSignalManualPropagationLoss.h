#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the manual propagation loss for the given spoofer signal. Value is used only if SetSpoofTxUseManualPropagationLoss has been set on the corresponding spoofer. This value is not preserved after simulation end.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------------------------------------------------------------------------------------------
    /// PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class SetSpoofSignalManualPropagationLoss;
    typedef std::shared_ptr<SetSpoofSignalManualPropagationLoss> SetSpoofSignalManualPropagationLossPtr;
    
    
    class SetSpoofSignalManualPropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofSignalManualPropagationLoss();

      SetSpoofSignalManualPropagationLoss(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static SetSpoofSignalManualPropagationLossPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId);
      static SetSpoofSignalManualPropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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
    
  }
}

