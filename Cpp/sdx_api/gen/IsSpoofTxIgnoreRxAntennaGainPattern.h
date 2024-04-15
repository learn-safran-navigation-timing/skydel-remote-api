#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a spoofer ignore the receiver's antenna gain pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaGainPattern> IsSpoofTxIgnoreRxAntennaGainPatternPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxIgnoreRxAntennaGainPattern();

      IsSpoofTxIgnoreRxAntennaGainPattern(const std::string& id);

      static IsSpoofTxIgnoreRxAntennaGainPatternPtr create(const std::string& id);
      static IsSpoofTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr);
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

