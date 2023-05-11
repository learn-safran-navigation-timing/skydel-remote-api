#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set antenna offset and orientation relative to body frame.
    /// The origin of the body frame follows the vehicle trajectory.
    /// When the body yaw/pitch/roll are zeros, the body X-axis is pointing north
    ///                          Y-axis is pointing east
    ///                          Z-axis is pointing down
    /// The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and
    /// the Roll is rotating arond the X-axis of the body frame.
    ///
    /// Name  Type            Description
    /// ----- --------------- --------------------------------------------
    /// X     double          Antenna X offset in the body frame (meter)
    /// Y     double          Antenna Y offset in the body frame (meter)
    /// Z     double          Antenna Z offset in the body frame (meter)
    /// Yaw   double          Antenna Yaw offset in the body frame (rad)
    /// Pitch double          Antenna Pitch offset in the body frame (rad)
    /// Roll  double          Antenna Roll offset in the body frame (rad)
    /// Name  optional string Unique vehicle antenna name
    ///

    class SetVehicleAntennaOffset;
    typedef std::shared_ptr<SetVehicleAntennaOffset> SetVehicleAntennaOffsetPtr;
    
    
    class SetVehicleAntennaOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetVehicleAntennaOffset();

      SetVehicleAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name = {});

      static SetVehicleAntennaOffsetPtr create(double x, double y, double z, double yaw, double pitch, double roll, const Sdx::optional<std::string>& name = {});
      static SetVehicleAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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


      // **** name ****
      Sdx::optional<std::string> name() const;
      void setName(const Sdx::optional<std::string>& name);
    };
    
  }
}

