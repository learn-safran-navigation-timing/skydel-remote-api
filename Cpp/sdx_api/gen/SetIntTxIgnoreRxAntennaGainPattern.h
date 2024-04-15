#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a dynamic transmitter should ignore the receiver's antenna gain pattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<SetIntTxIgnoreRxAntennaGainPattern> SetIntTxIgnoreRxAntennaGainPatternPtr;
    
    
    class SetIntTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxIgnoreRxAntennaGainPattern();

      SetIntTxIgnoreRxAntennaGainPattern(bool ignore, const std::string& id);

      static SetIntTxIgnoreRxAntennaGainPatternPtr create(bool ignore, const std::string& id);
      static SetIntTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr);
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

