#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set antenna offset and orientation relative to body frame.
    /// The origin of the body frame follows the transmitter trajectory.
    /// When the body yaw/pitch/roll are zeros, the body X-axis is pointing north
    ///                          Y-axis is pointing east
    ///                          Z-axis is pointing down
    /// The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and
    /// the Roll is rotating arond the X-axis of the body frame.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// X     double Antenna X offset in the body frame
    /// Y     double Antenna Y offset in the body frame
    /// Z     double Antenna Z offset in the body frame
    /// Yaw   double Antenna Yaw offset in the body frame
    /// Pitch double Antenna Pitch offset in the body frame
    /// Roll  double Antenna Roll offset in the body frame
    /// Id    string Transmitter unique identifier.
    ///

    class SetSpoofTxAntennaOffset;
    typedef std::shared_ptr<SetSpoofTxAntennaOffset> SetSpoofTxAntennaOffsetPtr;
    
    
    class SetSpoofTxAntennaOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxAntennaOffset();

      SetSpoofTxAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static SetSpoofTxAntennaOffsetPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static SetSpoofTxAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

