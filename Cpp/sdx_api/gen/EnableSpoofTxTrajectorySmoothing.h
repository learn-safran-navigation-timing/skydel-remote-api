#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set trajectory smoothing for spoofer transmitter Track enabled or disabled
    ///
    /// Name    Type   Description
    /// ------- ------ ---------------------------------------------------------------------------
    /// Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.
    /// Id      string Transmitter unique identifier.
    ///

    class EnableSpoofTxTrajectorySmoothing;
    typedef std::shared_ptr<EnableSpoofTxTrajectorySmoothing> EnableSpoofTxTrajectorySmoothingPtr;
    
    
    class EnableSpoofTxTrajectorySmoothing : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableSpoofTxTrajectorySmoothing();

      EnableSpoofTxTrajectorySmoothing(bool enabled, const std::string& id);

      static EnableSpoofTxTrajectorySmoothingPtr create(bool enabled, const std::string& id);
      static EnableSpoofTxTrajectorySmoothingPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

