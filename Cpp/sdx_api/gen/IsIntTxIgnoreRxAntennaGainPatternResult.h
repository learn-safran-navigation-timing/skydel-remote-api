#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsIntTxIgnoreRxAntennaGainPattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsIntTxIgnoreRxAntennaGainPatternResult;
    typedef std::shared_ptr<IsIntTxIgnoreRxAntennaGainPatternResult> IsIntTxIgnoreRxAntennaGainPatternResultPtr;
    
    
    class IsIntTxIgnoreRxAntennaGainPatternResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsIntTxIgnoreRxAntennaGainPatternResult();

      IsIntTxIgnoreRxAntennaGainPatternResult(bool ignore, const std::string& id);

      IsIntTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id);

      static IsIntTxIgnoreRxAntennaGainPatternResultPtr create(bool ignore, const std::string& id);

      static IsIntTxIgnoreRxAntennaGainPatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
      static IsIntTxIgnoreRxAntennaGainPatternResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsIntTxIgnoreRxAntennaGainPatternResult);
  }
}

