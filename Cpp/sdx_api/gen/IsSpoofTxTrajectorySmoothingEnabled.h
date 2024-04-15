#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get trajectory smoothing for spoofer transmitter Track enabled or disabled
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxTrajectorySmoothingEnabled;
    typedef std::shared_ptr<IsSpoofTxTrajectorySmoothingEnabled> IsSpoofTxTrajectorySmoothingEnabledPtr;
    
    
    class IsSpoofTxTrajectorySmoothingEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxTrajectorySmoothingEnabled();

      IsSpoofTxTrajectorySmoothingEnabled(const std::string& id);

      static IsSpoofTxTrajectorySmoothingEnabledPtr create(const std::string& id);
      static IsSpoofTxTrajectorySmoothingEnabledPtr dynamicCast(CommandBasePtr ptr);
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

