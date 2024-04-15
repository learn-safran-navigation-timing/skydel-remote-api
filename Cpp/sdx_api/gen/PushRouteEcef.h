#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a route ecef node with speed. Must be called after BeginRouteDefinition and before EndRouteDefinition.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// Speed double Node speed in meters per second
    /// X     double X distance from earth-center in meters
    /// Y     double Y distance from earth-center in meters
    /// Z     double Z distance from earth-center in meters
    ///

    class PushRouteEcef;
    typedef std::shared_ptr<PushRouteEcef> PushRouteEcefPtr;
    
    
    class PushRouteEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      PushRouteEcef();

      PushRouteEcef(double speed, double x, double y, double z);

      static PushRouteEcefPtr create(double speed, double x, double y, double z);
      static PushRouteEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** speed ****
      double speed() const;
      void setSpeed(double speed);


      // **** x ****
      double x() const;
      void setX(double x);


      // **** y ****
      double y() const;
      void setY(double y);


      // **** z ****
      double z() const;
      void setZ(double z);
    };
    
  }
}

