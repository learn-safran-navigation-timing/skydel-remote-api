#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxTrajectory.
    ///
    /// Name           Type   Description
    /// -------------- ------ ---------------------------------------------------
    /// TrajectoryType string Type of the trajectory of the spoofer transmitters.
    /// Id             string Transmitter unique identifier.
    ///

    class GetSpoofTxTrajectoryResult;
    typedef std::shared_ptr<GetSpoofTxTrajectoryResult> GetSpoofTxTrajectoryResultPtr;
    
    
    class GetSpoofTxTrajectoryResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxTrajectoryResult();

      GetSpoofTxTrajectoryResult(const std::string& trajectoryType, const std::string& id);

      GetSpoofTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id);

      static GetSpoofTxTrajectoryResultPtr create(const std::string& trajectoryType, const std::string& id);

      static GetSpoofTxTrajectoryResultPtr create(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id);
      static GetSpoofTxTrajectoryResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** trajectoryType ****
      std::string trajectoryType() const;
      void setTrajectoryType(const std::string& trajectoryType);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxTrajectoryResult);
  }
}

