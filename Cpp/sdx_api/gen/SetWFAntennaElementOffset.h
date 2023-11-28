#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.
    /// 
    /// Set WF antenna offset and orientation relative to CRPA Antenna frame for the specified element index.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------
    /// X       double WF Element X offset in the CRPA antenna frame (meter)
    /// Y       double WF Element Y offset in the CRPA antenna frame (meter)
    /// Z       double WF Element Z offset in the CRPA antenna frame (meter)
    /// Yaw     double WF Element Yaw offset in the CRPA antenna frame (rad)
    /// Pitch   double WF Element Pitch offset in the CRPA antenna frame (rad)
    /// Roll    double WF Element Roll offset in the CRPA antenna frame (rad)
    /// Element int    One-based index for element in antenna.
    ///

    class SetWFAntennaElementOffset;
    typedef std::shared_ptr<SetWFAntennaElementOffset> SetWFAntennaElementOffsetPtr;
    
    
    class SetWFAntennaElementOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      SetWFAntennaElementOffset();

      SetWFAntennaElementOffset(double x, double y, double z, double yaw, double pitch, double roll, int element);

      static SetWFAntennaElementOffsetPtr create(double x, double y, double z, double yaw, double pitch, double roll, int element);
      static SetWFAntennaElementOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

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


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

