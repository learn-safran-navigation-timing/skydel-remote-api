#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get spoofer transmitter trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxTrajectory;
    typedef std::shared_ptr<GetSpoofTxTrajectory> GetSpoofTxTrajectoryPtr;
    
    
    class GetSpoofTxTrajectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxTrajectory();

      GetSpoofTxTrajectory(const std::string& id);

      static GetSpoofTxTrajectoryPtr create(const std::string& id);
      static GetSpoofTxTrajectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

