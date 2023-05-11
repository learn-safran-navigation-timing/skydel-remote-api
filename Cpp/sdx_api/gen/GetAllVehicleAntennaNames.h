#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of all vehicle antenna names
    ///
    /// 
    ///

    class GetAllVehicleAntennaNames;
    typedef std::shared_ptr<GetAllVehicleAntennaNames> GetAllVehicleAntennaNamesPtr;
    
    
    class GetAllVehicleAntennaNames : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllVehicleAntennaNames();

      static GetAllVehicleAntennaNamesPtr create();
      static GetAllVehicleAntennaNamesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

