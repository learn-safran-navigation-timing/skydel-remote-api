#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsGroundVehicleTerrainFollowingEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------------------------------------------------------------------------
    /// Enabled bool If true, the altitude of ground vehicles is automatically adjusted to follow the terrain surface.
    ///

    class IsGroundVehicleTerrainFollowingEnabledResult;
    typedef std::shared_ptr<IsGroundVehicleTerrainFollowingEnabledResult> IsGroundVehicleTerrainFollowingEnabledResultPtr;
    
    
    class IsGroundVehicleTerrainFollowingEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsGroundVehicleTerrainFollowingEnabledResult();

      IsGroundVehicleTerrainFollowingEnabledResult(bool enabled);

      IsGroundVehicleTerrainFollowingEnabledResult(CommandBasePtr relatedCommand, bool enabled);

      static IsGroundVehicleTerrainFollowingEnabledResultPtr create(bool enabled);

      static IsGroundVehicleTerrainFollowingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled);
      static IsGroundVehicleTerrainFollowingEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsGroundVehicleTerrainFollowingEnabledResult);
  }
}

