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
    /// Result of GetIntTxVehicleType.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne")
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxVehicleTypeResult;
    typedef std::shared_ptr<GetIntTxVehicleTypeResult> GetIntTxVehicleTypeResultPtr;
    
    
    class GetIntTxVehicleTypeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxVehicleTypeResult();

      GetIntTxVehicleTypeResult(const std::string& type, const std::string& id);

      GetIntTxVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& id);

      static GetIntTxVehicleTypeResultPtr create(const std::string& type, const std::string& id);

      static GetIntTxVehicleTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& type, const std::string& id);
      static GetIntTxVehicleTypeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxVehicleTypeResult);
  }
}

