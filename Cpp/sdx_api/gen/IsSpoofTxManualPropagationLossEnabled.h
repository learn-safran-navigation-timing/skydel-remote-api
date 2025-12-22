#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells whether a spoofer uses propagation loss values provided by the user.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------------------
    /// Id   string Spoofing transmitter unique identifier.
    ///

    class IsSpoofTxManualPropagationLossEnabled;
    typedef std::shared_ptr<IsSpoofTxManualPropagationLossEnabled> IsSpoofTxManualPropagationLossEnabledPtr;
    
    
    class IsSpoofTxManualPropagationLossEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxManualPropagationLossEnabled();

      IsSpoofTxManualPropagationLossEnabled(const std::string& id);

      static IsSpoofTxManualPropagationLossEnabledPtr create(const std::string& id);
      static IsSpoofTxManualPropagationLossEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

