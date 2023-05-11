#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// End receiving simulated vehicle informations.
    ///
    /// 
    ///

    class EndVehicleInfo;
    typedef std::shared_ptr<EndVehicleInfo> EndVehicleInfoPtr;
    
    
    class EndVehicleInfo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EndVehicleInfo();

      static EndVehicleInfoPtr create();
      static EndVehicleInfoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

