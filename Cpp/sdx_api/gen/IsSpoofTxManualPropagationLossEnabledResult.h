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
    /// Result of IsSpoofTxManualPropagationLossEnabled.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Manual bool   If true, propagation loss will be 1000 dB until set manually.
    /// Id     string Spoofing transmitter unique identifier.
    ///

    class IsSpoofTxManualPropagationLossEnabledResult;
    typedef std::shared_ptr<IsSpoofTxManualPropagationLossEnabledResult> IsSpoofTxManualPropagationLossEnabledResultPtr;
    
    
    class IsSpoofTxManualPropagationLossEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxManualPropagationLossEnabledResult();

      IsSpoofTxManualPropagationLossEnabledResult(bool manual, const std::string& id);

      IsSpoofTxManualPropagationLossEnabledResult(CommandBasePtr relatedCommand, bool manual, const std::string& id);

      static IsSpoofTxManualPropagationLossEnabledResultPtr create(bool manual, const std::string& id);

      static IsSpoofTxManualPropagationLossEnabledResultPtr create(CommandBasePtr relatedCommand, bool manual, const std::string& id);
      static IsSpoofTxManualPropagationLossEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** manual ****
      bool manual() const;
      void setManual(bool manual);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxManualPropagationLossEnabledResult);
  }
}

