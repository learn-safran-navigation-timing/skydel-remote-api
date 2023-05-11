#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsIntTxIgnoreRxAntennaPhasePattern.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna phase pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsIntTxIgnoreRxAntennaPhasePatternResult;
    typedef std::shared_ptr<IsIntTxIgnoreRxAntennaPhasePatternResult> IsIntTxIgnoreRxAntennaPhasePatternResultPtr;
    
    
    class IsIntTxIgnoreRxAntennaPhasePatternResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsIntTxIgnoreRxAntennaPhasePatternResult();

      IsIntTxIgnoreRxAntennaPhasePatternResult(bool ignore, const std::string& id);

      IsIntTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id);

      static IsIntTxIgnoreRxAntennaPhasePatternResultPtr create(bool ignore, const std::string& id);

      static IsIntTxIgnoreRxAntennaPhasePatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
      static IsIntTxIgnoreRxAntennaPhasePatternResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsIntTxIgnoreRxAntennaPhasePatternResult);
  }
}

