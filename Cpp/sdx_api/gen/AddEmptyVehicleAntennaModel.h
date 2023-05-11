#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Create an empty vehicle antenna model.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Name string Vehicle antenna model name
    ///

    class AddEmptyVehicleAntennaModel;
    typedef std::shared_ptr<AddEmptyVehicleAntennaModel> AddEmptyVehicleAntennaModelPtr;
    
    
    class AddEmptyVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      AddEmptyVehicleAntennaModel();

      AddEmptyVehicleAntennaModel(const std::string& name);

      static AddEmptyVehicleAntennaModelPtr create(const std::string& name);
      static AddEmptyVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    
  }
}

