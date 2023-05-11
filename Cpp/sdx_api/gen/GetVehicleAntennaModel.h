#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get  all infos about this antenna model.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Name string Vehicle antenna model name
    ///

    class GetVehicleAntennaModel;
    typedef std::shared_ptr<GetVehicleAntennaModel> GetVehicleAntennaModelPtr;
    
    
    class GetVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleAntennaModel();

      GetVehicleAntennaModel(const std::string& name);

      static GetVehicleAntennaModelPtr create(const std::string& name);
      static GetVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    
  }
}

