#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDefaultVehicleAntennaModel.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Name string Default antenna model name.
    ///

    class GetDefaultVehicleAntennaModelResult;
    typedef std::shared_ptr<GetDefaultVehicleAntennaModelResult> GetDefaultVehicleAntennaModelResultPtr;
    
    
    class GetDefaultVehicleAntennaModelResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDefaultVehicleAntennaModelResult();

      GetDefaultVehicleAntennaModelResult(const std::string& name);

      GetDefaultVehicleAntennaModelResult(CommandBasePtr relatedCommand, const std::string& name);

      static GetDefaultVehicleAntennaModelResultPtr create(const std::string& name);

      static GetDefaultVehicleAntennaModelResultPtr create(CommandBasePtr relatedCommand, const std::string& name);
      static GetDefaultVehicleAntennaModelResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetDefaultVehicleAntennaModelResult);
  }
}

