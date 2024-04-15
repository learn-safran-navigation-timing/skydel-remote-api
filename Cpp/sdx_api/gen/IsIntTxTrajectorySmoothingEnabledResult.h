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
    /// Result of IsIntTxTrajectorySmoothingEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------
    /// Enabled bool   If true, interference trajectory will be smoothed during simulation
    /// Id      string Transmitter unique identifier.
    ///

    class IsIntTxTrajectorySmoothingEnabledResult;
    typedef std::shared_ptr<IsIntTxTrajectorySmoothingEnabledResult> IsIntTxTrajectorySmoothingEnabledResultPtr;
    
    
    class IsIntTxTrajectorySmoothingEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIntTxTrajectorySmoothingEnabledResult();

      IsIntTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id);

      IsIntTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id);

      static IsIntTxTrajectorySmoothingEnabledResultPtr create(bool enabled, const std::string& id);

      static IsIntTxTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::string& id);
      static IsIntTxTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsIntTxTrajectorySmoothingEnabledResult);
  }
}

