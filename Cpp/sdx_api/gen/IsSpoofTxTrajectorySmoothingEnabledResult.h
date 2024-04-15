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
    /// Result of IsSpoofTxTrajectorySmoothingEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ ---------------------------------------------------------------------------
    /// Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.
    /// Id      string Transmitter unique identifier.
    ///

    class IsSpoofTxTrajectorySmoothingEnabledResult;
    typedef std::shared_ptr<IsSpoofTxTrajectorySmoothingEnabledResult> IsSpoofTxTrajectorySmoothingEnabledResultPtr;
    
    
    class IsSpoofTxTrajectorySmoothingEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxTrajectorySmoothingEnabledResult();

      IsSpoofTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id);

      IsSpoofTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id);

      static IsSpoofTxTrajectorySmoothingEnabledResultPtr create(bool enabled, const std::string& id);

      static IsSpoofTxTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::string& id);
      static IsSpoofTxTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxTrajectorySmoothingEnabledResult);
  }
}

