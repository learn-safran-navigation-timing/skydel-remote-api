#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells whether a dynamic interference transmitter uses propagation loss values provided by the user.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------------
    /// Id   string Interference transmitter unique identifier.
    ///

    class IsIntTxManualPropagationLossEnabled;
    typedef std::shared_ptr<IsIntTxManualPropagationLossEnabled> IsIntTxManualPropagationLossEnabledPtr;
    
    
    class IsIntTxManualPropagationLossEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIntTxManualPropagationLossEnabled();

      IsIntTxManualPropagationLossEnabled(const std::string& id);

      static IsIntTxManualPropagationLossEnabledPtr create(const std::string& id);
      static IsIntTxManualPropagationLossEnabledPtr dynamicCast(CommandBasePtr ptr);
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

