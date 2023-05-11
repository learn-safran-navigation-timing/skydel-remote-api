#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear NMEA trajectory file
    ///
    /// 
    ///

    class ClearVehiculeTrajectory;
    typedef std::shared_ptr<ClearVehiculeTrajectory> ClearVehiculeTrajectoryPtr;
    
    
    class ClearVehiculeTrajectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearVehiculeTrajectory();

      static ClearVehiculeTrajectoryPtr create();
      static ClearVehiculeTrajectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

