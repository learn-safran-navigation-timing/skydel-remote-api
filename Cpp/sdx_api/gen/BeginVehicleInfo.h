#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begin receiving simulated vehicle informations. 
    /// During simulation, you must call RemoteSimulator.lastVehicleInfo to get current simulation statistics or RemoteSimulator.nextVehicleInfo to get pending simulation statistics
    ///
    /// 
    ///

    class BeginVehicleInfo;
    typedef std::shared_ptr<BeginVehicleInfo> BeginVehicleInfoPtr;
    
    
    class BeginVehicleInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      BeginVehicleInfo();

      static BeginVehicleInfoPtr create();
      static BeginVehicleInfoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

