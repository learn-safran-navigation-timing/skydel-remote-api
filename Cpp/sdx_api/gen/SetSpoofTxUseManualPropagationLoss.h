#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a spoofer should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Manual bool   If true, propagation loss will be 1000 dB until set manually.
    /// Id     string Spoofing transmitter unique identifier.
    ///

    class SetSpoofTxUseManualPropagationLoss;
    typedef std::shared_ptr<SetSpoofTxUseManualPropagationLoss> SetSpoofTxUseManualPropagationLossPtr;
    
    
    class SetSpoofTxUseManualPropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxUseManualPropagationLoss();

      SetSpoofTxUseManualPropagationLoss(bool manual, const std::string& id);

      static SetSpoofTxUseManualPropagationLossPtr create(bool manual, const std::string& id);
      static SetSpoofTxUseManualPropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** manual ****
      bool manual() const;
      void setManual(bool manual);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

