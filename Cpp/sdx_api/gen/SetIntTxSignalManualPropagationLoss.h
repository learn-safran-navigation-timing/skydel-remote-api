#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Sets the manual propagation loss for the given interference signal. This value is only applied when manual propagation losses are enabled for the transmitter and is discarded once the simulation ends.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------------------------------------------------------------------------------------------
    /// PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class SetIntTxSignalManualPropagationLoss;
    typedef std::shared_ptr<SetIntTxSignalManualPropagationLoss> SetIntTxSignalManualPropagationLossPtr;
    
    
    class SetIntTxSignalManualPropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxSignalManualPropagationLoss();

      SetIntTxSignalManualPropagationLoss(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static SetIntTxSignalManualPropagationLossPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId);
      static SetIntTxSignalManualPropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

