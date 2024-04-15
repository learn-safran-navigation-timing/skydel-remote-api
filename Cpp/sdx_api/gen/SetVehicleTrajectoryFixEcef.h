#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle static position and orientation
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

    class SetVehicleTrajectoryFixEcef;
    typedef std::shared_ptr<SetVehicleTrajectoryFixEcef> SetVehicleTrajectoryFixEcefPtr;
    
    
    class SetVehicleTrajectoryFixEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetVehicleTrajectoryFixEcef();

      SetVehicleTrajectoryFixEcef(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);

      static SetVehicleTrajectoryFixEcefPtr create(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll);
      static SetVehicleTrajectoryFixEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

