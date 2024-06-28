#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set spoofer transmitter circular trajectory
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------
    /// Lat         double          Center latitude (rad)
    /// Lon         double          Center longitude (rad)
    /// Alt         double          Altitude (m)
    /// Radius      double          Radius (m)
    /// Speed       double          Speed (m/s)
    /// Clockwise   bool            If true, vehicle turns clockwise
    /// Id          string          Transmitter unique identifier.
    /// OriginAngle optional double Vehicle angle at elapsed time 0.
    ///

    class SetSpoofTxCircular;
    typedef std::shared_ptr<SetSpoofTxCircular> SetSpoofTxCircularPtr;
    
    
    class SetSpoofTxCircular : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxCircular();

      SetSpoofTxCircular(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle = {});

      static SetSpoofTxCircularPtr create(double lat, double lon, double alt, double radius, double speed, bool clockwise, const std::string& id, const std::optional<double>& originAngle = {});
      static SetSpoofTxCircularPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** lat ****
      double lat() const;
      void setLat(double lat);


      // **** lon ****
      double lon() const;
      void setLon(double lon);


      // **** alt ****
      double alt() const;
      void setAlt(double alt);


      // **** radius ****
      double radius() const;
      void setRadius(double radius);


      // **** speed ****
      double speed() const;
      void setSpeed(double speed);


      // **** clockwise ****
      bool clockwise() const;
      void setClockwise(bool clockwise);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** originAngle ****
      std::optional<double> originAngle() const;
      void setOriginAngle(const std::optional<double>& originAngle);
    };
    
  }
}

