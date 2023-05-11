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
    /// Lat   double Latitude (rad)
    /// Lon   double Longitude (rad)
    /// Alt   double Altitude (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    ///

    class SetVehicleTrajectoryFix;
    typedef std::shared_ptr<SetVehicleTrajectoryFix> SetVehicleTrajectoryFixPtr;
    
    
    class SetVehicleTrajectoryFix : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetVehicleTrajectoryFix();

      SetVehicleTrajectoryFix(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);

      static SetVehicleTrajectoryFixPtr create(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);
      static SetVehicleTrajectoryFixPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** lat ****
      double lat() const;
      void setLat(double lat);


      // **** lon ****
      double lon() const;
      void setLon(double lon);


      // **** alt ****
      double alt() const;
      void setAlt(double alt);


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

