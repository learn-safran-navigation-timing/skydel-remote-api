#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsAttitudeToZeroForced.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, vehicle won't rotate during simulation
    ///

    class IsAttitudeToZeroForcedResult;
    typedef std::shared_ptr<IsAttitudeToZeroForcedResult> IsAttitudeToZeroForcedResultPtr;
    
    
    class IsAttitudeToZeroForcedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsAttitudeToZeroForcedResult();

      IsAttitudeToZeroForcedResult(bool enabled);

      IsAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled);

      static IsAttitudeToZeroForcedResultPtr create(bool enabled);

      static IsAttitudeToZeroForcedResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsAttitudeToZeroForcedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsAttitudeToZeroForcedResult);
  }
}

