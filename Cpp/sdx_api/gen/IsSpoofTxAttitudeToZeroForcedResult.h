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
    /// Result of IsSpoofTxAttitudeToZeroForced.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------
    /// Enabled bool   If true, spoofer transmitter vehicle won't rotate during simulation
    /// Id      string Transmitter unique identifier.
    ///

    class IsSpoofTxAttitudeToZeroForcedResult;
    typedef std::shared_ptr<IsSpoofTxAttitudeToZeroForcedResult> IsSpoofTxAttitudeToZeroForcedResultPtr;
    
    
    class IsSpoofTxAttitudeToZeroForcedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxAttitudeToZeroForcedResult();

      IsSpoofTxAttitudeToZeroForcedResult(bool enabled, const std::string& id);

      IsSpoofTxAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id);

      static IsSpoofTxAttitudeToZeroForcedResultPtr create(bool enabled, const std::string& id);

      static IsSpoofTxAttitudeToZeroForcedResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::string& id);
      static IsSpoofTxAttitudeToZeroForcedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxAttitudeToZeroForcedResult);
  }
}

