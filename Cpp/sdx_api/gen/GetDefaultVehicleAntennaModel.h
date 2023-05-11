#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the default vehicle antenna model.
    ///
    /// 
    ///

    class GetDefaultVehicleAntennaModel;
    typedef std::shared_ptr<GetDefaultVehicleAntennaModel> GetDefaultVehicleAntennaModelPtr;
    
    
    class GetDefaultVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDefaultVehicleAntennaModel();

      static GetDefaultVehicleAntennaModelPtr create();
      static GetDefaultVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

