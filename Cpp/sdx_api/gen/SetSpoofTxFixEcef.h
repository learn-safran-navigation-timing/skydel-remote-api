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
    /// X     double ECEF X (m)
    /// Y     double ECEF Y (m)
    /// Z     double ECEF Z (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    /// Id    string Transmitter unique identifier.
    ///

    class SetSpoofTxFixEcef;
    typedef std::shared_ptr<SetSpoofTxFixEcef> SetSpoofTxFixEcefPtr;
    
    
    class SetSpoofTxFixEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxFixEcef();

      SetSpoofTxFixEcef(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);

      static SetSpoofTxFixEcefPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id);
      static SetSpoofTxFixEcefPtr dynamicCast(CommandBasePtr ptr);
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

