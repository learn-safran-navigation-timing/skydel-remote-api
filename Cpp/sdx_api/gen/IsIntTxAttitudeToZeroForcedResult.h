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
    /// Result of IsIntTxAttitudeToZeroForced.
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------------------------------
    /// Enabled bool   If true, interference vehicle won't rotate during simulation
    /// Id      string Transmitter unique identifier.
    ///

    class IsIntTxAttitudeToZeroForcedResult;
    typedef std::shared_ptr<IsIntTxAttitudeToZeroForcedResult> IsIntTxAttitudeToZeroForcedResultPtr;
    
    
    class IsIntTxAttitudeToZeroForcedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsIntTxAttitudeToZeroForcedResult();

      IsIntTxAttitudeToZeroForcedResult(bool enabled, const std::string& id);

      IsIntTxAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id);

      static IsIntTxAttitudeToZeroForcedResultPtr create(bool enabled, const std::string& id);

      static IsIntTxAttitudeToZeroForcedResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::string& id);
      static IsIntTxAttitudeToZeroForcedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsIntTxAttitudeToZeroForcedResult);
  }
}

