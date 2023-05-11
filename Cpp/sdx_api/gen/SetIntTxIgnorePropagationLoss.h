#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a dynamic transmitter should ignore propagation loss or not.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------------------------------
    /// Ignore bool   If true, propagation loss will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnorePropagationLoss;
    typedef std::shared_ptr<SetIntTxIgnorePropagationLoss> SetIntTxIgnorePropagationLossPtr;
    
    
    class SetIntTxIgnorePropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxIgnorePropagationLoss();

      SetIntTxIgnorePropagationLoss(bool ignore, const std::string& id);

      static SetIntTxIgnorePropagationLossPtr create(bool ignore, const std::string& id);
      static SetIntTxIgnorePropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

