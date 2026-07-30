#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsGnssSignalTerrainObscurationEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------
    /// Enabled bool If true, GNSS signals from satellites obscured by terrain will not reach the receiver.
    ///

    class IsGnssSignalTerrainObscurationEnabledResult;
    typedef std::shared_ptr<IsGnssSignalTerrainObscurationEnabledResult> IsGnssSignalTerrainObscurationEnabledResultPtr;
    
    
    class IsGnssSignalTerrainObscurationEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsGnssSignalTerrainObscurationEnabledResult();

      IsGnssSignalTerrainObscurationEnabledResult(bool enabled);

      IsGnssSignalTerrainObscurationEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsGnssSignalTerrainObscurationEnabledResultPtr create(bool enabled);

      static IsGnssSignalTerrainObscurationEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsGnssSignalTerrainObscurationEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsGnssSignalTerrainObscurationEnabledResult);
  }
}

