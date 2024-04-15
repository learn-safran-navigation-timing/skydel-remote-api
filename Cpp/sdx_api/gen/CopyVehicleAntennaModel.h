#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Copy a vehicle antenna model.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------------
    /// Name     string Reference vehicle antenna model name
    /// CopyName string Copy vehicle antenna model name
    ///

    class CopyVehicleAntennaModel;
    typedef std::shared_ptr<CopyVehicleAntennaModel> CopyVehicleAntennaModelPtr;
    
    
    class CopyVehicleAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      CopyVehicleAntennaModel();

      CopyVehicleAntennaModel(const std::string& name, const std::string& copyName);

      static CopyVehicleAntennaModelPtr create(const std::string& name, const std::string& copyName);
      static CopyVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** copyName ****
      std::string copyName() const;
      void setCopyName(const std::string& copyName);
    };
    
  }
}

