#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set spoofer transmitter static position and orientation
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// Lat   double Latitude (rad)
    /// Lon   double Longitude (rad)
    /// Alt   double Altitude (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    /// Id    string Transmitter unique identifier.
    ///

    class SetSpoofTxFix;
    typedef std::shared_ptr<SetSpoofTxFix> SetSpoofTxFixPtr;
    
    
    class SetSpoofTxFix : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxFix();

      SetSpoofTxFix(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id);

      static SetSpoofTxFixPtr create(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id);
      static SetSpoofTxFixPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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


      // **** yaw ****
      double yaw() const;
      void setYaw(double yaw);


      // **** pitch ****
      double pitch() const;
      void setPitch(double pitch);


      // **** roll ****
      double roll() const;
      void setRoll(double roll);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

