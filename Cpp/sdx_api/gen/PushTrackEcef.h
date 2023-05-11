#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a track ecef node. Must be called after BeginTrackDefinition and before EndTrackDefinition.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------
    /// Time int    Node Timestamp in miliseconds
    /// X    double X distance from earth-center in meters
    /// Y    double Y distance from earth-center in meters
    /// Z    double Z distance from earth-center in meters
    ///

    class PushTrackEcef;
    typedef std::shared_ptr<PushTrackEcef> PushTrackEcefPtr;
    
    
    class PushTrackEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      PushTrackEcef();

      PushTrackEcef(int time, double x, double y, double z);

      static PushTrackEcefPtr create(int time, double x, double y, double z);
      static PushTrackEcefPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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
    };
    
  }
}

