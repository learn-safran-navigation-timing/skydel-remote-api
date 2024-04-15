
#include "GetVehicleType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleType::CmdName = "GetVehicleType";
    const char* const GetVehicleType::Documentation = "Get vehicle type for Route Trajectory";
    const char* const GetVehicleType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVehicleType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVehicleType);


    GetVehicleType::GetVehicleType()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetVehicleTypePtr GetVehicleType::create()
    {
      return std::make_shared<GetVehicleType>();
    }

    GetVehicleTypePtr GetVehicleType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleType>(ptr);
    }

    bool GetVehicleType::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetVehicleType::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVehicleType::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
