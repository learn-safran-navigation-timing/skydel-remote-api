#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Rename a vehicle antenna model.
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------
    /// Name    string Reference vehicle antenna model name
    /// NewName string New vehicle antenna model name
    ///

    class RenameVehicleAntennaModel;
    typedef std::shared_ptr<RenameVehicleAntennaModel> RenameVehicleAntennaModelPtr;
    
    
    class RenameVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RenameVehicleAntennaModel();

      RenameVehicleAntennaModel(const std::string& name, const std::string& newName);

      static RenameVehicleAntennaModelPtr create(const std::string& name, const std::string& newName);
      static RenameVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** newName ****
      std::string newName() const;
      void setNewName(const std::string& newName);
    };
    
  }
}

