#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxVehicleType.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne").
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxVehicleTypeResult;
    typedef std::shared_ptr<GetSpoofTxVehicleTypeResult> GetSpoofTxVehicleTypeResultPtr;
    
    
    class GetSpoofTxVehicleTypeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSpoofTxVehicleTypeResult();

      GetSpoofTxVehicleTypeResult(const std::string& type, const std::string& id);

      GetSpoofTxVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& id);

      static GetSpoofTxVehicleTypeResultPtr create(const std::string& type, const std::string& id);

      static GetSpoofTxVehicleTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& type, const std::string& id);
      static GetSpoofTxVehicleTypeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSpoofTxVehicleTypeResult);
  }
}

