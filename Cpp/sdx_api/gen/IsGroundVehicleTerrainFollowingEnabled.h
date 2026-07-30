#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells whether ground vehicles follow the terrain surface.
    ///
    /// 
    ///

    class IsGroundVehicleTerrainFollowingEnabled;
    typedef std::shared_ptr<IsGroundVehicleTerrainFollowingEnabled> IsGroundVehicleTerrainFollowingEnabledPtr;
    
    
    class IsGroundVehicleTerrainFollowingEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsGroundVehicleTerrainFollowingEnabled();

      static IsGroundVehicleTerrainFollowingEnabledPtr create();
      static IsGroundVehicleTerrainFollowingEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

