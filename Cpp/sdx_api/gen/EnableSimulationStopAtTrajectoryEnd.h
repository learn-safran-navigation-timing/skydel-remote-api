#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------------
    /// Enabled bool If true, simulation will stop when the vehicle will reach trajectory end
    ///

    class EnableSimulationStopAtTrajectoryEnd;
    typedef std::shared_ptr<EnableSimulationStopAtTrajectoryEnd> EnableSimulationStopAtTrajectoryEndPtr;
    
    
    class EnableSimulationStopAtTrajectoryEnd : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSimulationStopAtTrajectoryEnd();

      EnableSimulationStopAtTrajectoryEnd(bool enabled);

      static EnableSimulationStopAtTrajectoryEndPtr create(bool enabled);
      static EnableSimulationStopAtTrajectoryEndPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

