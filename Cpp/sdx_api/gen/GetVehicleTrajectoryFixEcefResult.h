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
    /// Result of GetVehicleTrajectoryFixEcef.
    ///
    /// Name  Type   Description
    /// ----- ------ -----------------------
    /// Type  string Trajectory type ("Fix")
    /// X     double ECEF X (m)
    /// Y     double ECEF Y (m)
    /// Z     double ECEF Z (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    ///

    class GetVehicleTrajectoryFixEcefResult;
    typedef std::shared_ptr<GetVehicleTrajectoryFixEcefResult> GetVehicleTrajectoryFixEcefResultPtr;
    
    
    class GetVehicleTrajectoryFixEcefResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetVehicleTrajectoryFixEcefResult();

      GetVehicleTrajectoryFixEcefResult(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);

      GetVehicleTrajectoryFixEcefResult(CommandBasePtr relatedCommand, const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);

      static GetVehicleTrajectoryFixEcefResultPtr create(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);

      static GetVehicleTrajectoryFixEcefResultPtr create(CommandBasePtr relatedCommand, const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);
      static GetVehicleTrajectoryFixEcefResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);


      // **** yaw ****
      double yaw() const;
      void setYaw(double yaw);


      // **** pitch ****
      double pitch() const;
      void setPitch(double pitch);


      // **** roll ****
      double roll() const;
      void setRoll(double roll);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleTrajectoryFixEcefResult);
  }
}

