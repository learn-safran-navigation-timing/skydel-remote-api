#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxTrajectory.
    ///
    /// Name           Type   Description
    /// -------------- ------ ---------------------------------------------------------
    /// TrajectoryType string Type of the trajectory of the interferences transmitters.
    /// Id             string Transmitter unique identifier.
    ///

    class GetIntTxTrajectoryResult;
    typedef std::shared_ptr<GetIntTxTrajectoryResult> GetIntTxTrajectoryResultPtr;
    
    
    class GetIntTxTrajectoryResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxTrajectoryResult();

      GetIntTxTrajectoryResult(const std::string& trajectoryType, const std::string& id);

      GetIntTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id);

      static GetIntTxTrajectoryResultPtr create(const std::string& trajectoryType, const std::string& id);

      static GetIntTxTrajectoryResultPtr create(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id);
      static GetIntTxTrajectoryResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** trajectoryType ****
      std::string trajectoryType() const;
      void setTrajectoryType(const std::string& trajectoryType);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxTrajectoryResult);
  }
}

