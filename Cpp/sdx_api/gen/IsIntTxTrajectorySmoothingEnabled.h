#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get trajectory smoothing for interference Track enabled or disabled
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsIntTxTrajectorySmoothingEnabled;
    typedef std::shared_ptr<IsIntTxTrajectorySmoothingEnabled> IsIntTxTrajectorySmoothingEnabledPtr;
    
    
    class IsIntTxTrajectorySmoothingEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsIntTxTrajectorySmoothingEnabled();

      IsIntTxTrajectorySmoothingEnabled(const std::string& id);

      static IsIntTxTrajectorySmoothingEnabledPtr create(const std::string& id);
      static IsIntTxTrajectorySmoothingEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

