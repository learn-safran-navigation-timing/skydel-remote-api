#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the default vehicle antenna model.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Name string Default antenna model name.
    ///

    class SetDefaultVehicleAntennaModel;
    typedef std::shared_ptr<SetDefaultVehicleAntennaModel> SetDefaultVehicleAntennaModelPtr;
    
    
    class SetDefaultVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetDefaultVehicleAntennaModel();

      SetDefaultVehicleAntennaModel(const std::string& name);

      static SetDefaultVehicleAntennaModelPtr create(const std::string& name);
      static SetDefaultVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    
  }
}

