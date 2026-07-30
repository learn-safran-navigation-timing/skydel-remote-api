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
    /// Result of GetSpoofSignalPropagationLoss.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------
    /// PropagationLoss double The signal's propagation loss value in dB.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class GetSpoofSignalPropagationLossResult;
    typedef std::shared_ptr<GetSpoofSignalPropagationLossResult> GetSpoofSignalPropagationLossResultPtr;
    
    
    class GetSpoofSignalPropagationLossResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofSignalPropagationLossResult();

      GetSpoofSignalPropagationLossResult(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      GetSpoofSignalPropagationLossResult(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetSpoofSignalPropagationLossResultPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId);

      static GetSpoofSignalPropagationLossResultPtr create(CommandBasePtr relatedCommand, double propagationLoss, const std::string& transmitterId, const std::string& signalId);
      static GetSpoofSignalPropagationLossResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofSignalPropagationLossResult);
  }
}

