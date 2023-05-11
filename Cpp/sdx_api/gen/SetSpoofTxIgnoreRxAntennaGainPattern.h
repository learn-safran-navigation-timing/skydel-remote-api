#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a spoofer should ignore the receiver's antenna gain pattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetSpoofTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<SetSpoofTxIgnoreRxAntennaGainPattern> SetSpoofTxIgnoreRxAntennaGainPatternPtr;
    
    
    class SetSpoofTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxIgnoreRxAntennaGainPattern();

      SetSpoofTxIgnoreRxAntennaGainPattern(bool ignore, const std::string& id);

      static SetSpoofTxIgnoreRxAntennaGainPatternPtr create(bool ignore, const std::string& id);
      static SetSpoofTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr);
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

