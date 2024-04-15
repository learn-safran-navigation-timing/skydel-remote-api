#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push an interference track ecef node. Must be called after BeginIntTxTrackDefinition and before EndIntTxTrackDefinition.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------
    /// Time int    Node Timestamp in miliseconds
    /// X    double X distance from earth-center in meters
    /// Y    double Y distance from earth-center in meters
    /// Z    double Z distance from earth-center in meters
    /// Id   string Transmitter unique identifier.
    ///

    class PushIntTxTrackEcef;
    typedef std::shared_ptr<PushIntTxTrackEcef> PushIntTxTrackEcefPtr;
    
    
    class PushIntTxTrackEcef : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      PushIntTxTrackEcef();

      PushIntTxTrackEcef(int time, double x, double y, double z, const std::string& id);

      static PushIntTxTrackEcefPtr create(int time, double x, double y, double z, const std::string& id);
      static PushIntTxTrackEcefPtr dynamicCast(CommandBasePtr ptr);
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


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

