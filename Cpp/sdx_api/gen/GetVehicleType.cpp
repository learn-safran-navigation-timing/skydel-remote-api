
#include "gen/GetVehicleType.h"

#include "command_factory.h"
#include "command_result_factory.h"
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

    REGISTER_COMMAND_FACTORY(GetVehicleType);


    GetVehicleType::GetVehicleType()
      : CommandBase(CmdName)
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


    int GetVehicleType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
