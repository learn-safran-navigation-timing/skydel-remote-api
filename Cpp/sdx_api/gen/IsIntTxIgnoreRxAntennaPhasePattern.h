#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a dynamic transmitter ignore the receiver's antenna phase pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsIntTxIgnoreRxAntennaPhasePattern;
    typedef std::shared_ptr<IsIntTxIgnoreRxAntennaPhasePattern> IsIntTxIgnoreRxAntennaPhasePatternPtr;
    
    
    class IsIntTxIgnoreRxAntennaPhasePattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIntTxIgnoreRxAntennaPhasePattern();

      IsIntTxIgnoreRxAntennaPhasePattern(const std::string& id);

      static IsIntTxIgnoreRxAntennaPhasePatternPtr create(const std::string& id);
      static IsIntTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr);
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

