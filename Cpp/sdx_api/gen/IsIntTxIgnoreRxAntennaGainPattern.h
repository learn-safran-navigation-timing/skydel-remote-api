#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a dynamic transmitter ignore the receiver's antenna gain pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsIntTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<IsIntTxIgnoreRxAntennaGainPattern> IsIntTxIgnoreRxAntennaGainPatternPtr;
    
    
    class IsIntTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIntTxIgnoreRxAntennaGainPattern();

      IsIntTxIgnoreRxAntennaGainPattern(const std::string& id);

      static IsIntTxIgnoreRxAntennaGainPatternPtr create(const std::string& id);
      static IsIntTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr);
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

