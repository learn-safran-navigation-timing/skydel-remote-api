#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Delete a vehicle antenna model. The default vehicle antenna model can't be deleted.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Name string Vehicle antenna model name
    ///

    class DeleteVehicleAntennaModel;
    typedef std::shared_ptr<DeleteVehicleAntennaModel> DeleteVehicleAntennaModelPtr;
    
    
    class DeleteVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      DeleteVehicleAntennaModel();

      DeleteVehicleAntennaModel(const std::string& name);

      static DeleteVehicleAntennaModelPtr create(const std::string& name);
      static DeleteVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    
  }
}

