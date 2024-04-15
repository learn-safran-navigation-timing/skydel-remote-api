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
      static const char* const TargetId;


      GetDefaultVehicleAntennaModel();

      static GetDefaultVehicleAntennaModelPtr create();
      static GetDefaultVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

