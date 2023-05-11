#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a spoofer ignore the receiver's antenna phase pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaPhasePattern;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaPhasePattern> IsSpoofTxIgnoreRxAntennaPhasePatternPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaPhasePattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSpoofTxIgnoreRxAntennaPhasePattern();

      IsSpoofTxIgnoreRxAntennaPhasePattern(const std::string& id);

      static IsSpoofTxIgnoreRxAntennaPhasePatternPtr create(const std::string& id);
      static IsSpoofTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

