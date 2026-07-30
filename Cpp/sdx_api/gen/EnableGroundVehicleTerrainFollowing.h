#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) terrain-following behavior for ground vehicles.
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------------------------------------------------------------------------
    /// Enabled bool If true, the altitude of ground vehicles is automatically adjusted to follow the terrain surface.
    ///

    class EnableGroundVehicleTerrainFollowing;
    typedef std::shared_ptr<EnableGroundVehicleTerrainFollowing> EnableGroundVehicleTerrainFollowingPtr;
    
    
    class EnableGroundVehicleTerrainFollowing : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableGroundVehicleTerrainFollowing();

      EnableGroundVehicleTerrainFollowing(bool enabled);

      static EnableGroundVehicleTerrainFollowingPtr create(bool enabled);
      static EnableGroundVehicleTerrainFollowingPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

