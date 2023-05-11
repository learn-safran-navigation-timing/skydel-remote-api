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
    /// Result of GetVehicleTrajectoryFix.
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

    class GetVehicleTrajectoryFixResult;
    typedef std::shared_ptr<GetVehicleTrajectoryFixResult> GetVehicleTrajectoryFixResultPtr;
    
    
    class GetVehicleTrajectoryFixResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTrajectoryFixResult();

      GetVehicleTrajectoryFixResult(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);

      GetVehicleTrajectoryFixResult(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);

      static GetVehicleTrajectoryFixResultPtr create(const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);

      static GetVehicleTrajectoryFixResultPtr create(CommandBasePtr relatedCommand, const std::string& type, double lat, double lon, double alt, double yaw, double pitch, double roll);
      static GetVehicleTrajectoryFixResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetVehicleTrajectoryFixResult);
  }
}

