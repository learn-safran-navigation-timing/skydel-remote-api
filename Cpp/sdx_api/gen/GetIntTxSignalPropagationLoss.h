#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Gets the propagation loss value computed by Skydel for the specified interference signal.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string Signal unique identifier.
    ///

    class GetIntTxSignalPropagationLoss;
    typedef std::shared_ptr<GetIntTxSignalPropagationLoss> GetIntTxSignalPropagationLossPtr;
    
    
    class GetIntTxSignalPropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxSignalPropagationLoss();

      GetIntTxSignalPropagationLoss(const std::string& transmitterId, const std::string& signalId);

      static GetIntTxSignalPropagationLossPtr create(const std::string& transmitterId, const std::string& signalId);
      static GetIntTxSignalPropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);
    };
    
  }
}

