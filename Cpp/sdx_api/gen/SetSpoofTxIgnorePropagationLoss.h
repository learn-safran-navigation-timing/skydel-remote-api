#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a spoofer should ignore propagation loss or not.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------------------------------
    /// Ignore bool   If true, propagation loss will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetSpoofTxIgnorePropagationLoss;
    typedef std::shared_ptr<SetSpoofTxIgnorePropagationLoss> SetSpoofTxIgnorePropagationLossPtr;
    
    
    class SetSpoofTxIgnorePropagationLoss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxIgnorePropagationLoss();

      SetSpoofTxIgnorePropagationLoss(bool ignore, const std::string& id);

      static SetSpoofTxIgnorePropagationLossPtr create(bool ignore, const std::string& id);
      static SetSpoofTxIgnorePropagationLossPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

