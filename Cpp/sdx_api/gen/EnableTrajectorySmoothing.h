#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set trajectory smoothing for Track or Route enabled or disabled
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------
    /// Enabled bool If true, trajectory will be smoothed during simulation
    ///

    class EnableTrajectorySmoothing;
    typedef std::shared_ptr<EnableTrajectorySmoothing> EnableTrajectorySmoothingPtr;
    
    
    class EnableTrajectorySmoothing : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableTrajectorySmoothing();

      EnableTrajectorySmoothing(bool enabled);

      static EnableTrajectorySmoothingPtr create(bool enabled);
      static EnableTrajectorySmoothingPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

