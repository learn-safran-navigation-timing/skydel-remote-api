#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a track ecef and ned attitude node. Must be called after BeginTrackDefinition and before EndTrackDefinition.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// Time  int    Node Timestamp in miliseconds
    /// X     double X distance from earth-center in meters
    /// Y     double Y distance from earth-center in meters
    /// Z     double Z distance from earth-center in meters
    /// Yaw   double Yaw in radians
    /// Pitch double Pitch in radians
    /// Roll  double Roll in radians
    ///

    class PushTrackEcefNed;
    typedef std::shared_ptr<PushTrackEcefNed> PushTrackEcefNedPtr;
    
    
    class PushTrackEcefNed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      PushTrackEcefNed();

      PushTrackEcefNed(int time, double x, double y, double z, double yaw, double pitch, double roll);

      static PushTrackEcefNedPtr create(int time, double x, double y, double z, double yaw, double pitch, double roll);
      static PushTrackEcefNedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** time ****
      int time() const;
      void setTime(int time);


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

